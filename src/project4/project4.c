// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved.
// Licensed under the MIT License.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 32
#define DELIMITERS ", \t\n"

/** Represents text as a zero-terminated sequence of characters. */
typedef char *String;

/** Represents an 8-bit unsigned integer. */
typedef unsigned char Byte;

/** Represents an entry in the translation lookaside buffer (TLB). */
struct TlbEntry
{
    int tag;
    int physicalPageNumber;
};

/** Represents an entry in the physical set-associative cache memory. */
struct CacheLine
{
    int tag;
    Byte bytes[4];
};

/** Represents a simulated memory model. */
struct Model
{
    int pages[16];
    struct TlbEntry tlb[4][4];
    struct CacheLine cache[16];
};

/** Represents a simulated memory model. */
typedef struct Model *Model;

/**
 * Retrieves the next token from the buffered tokenizer, converted to an
 * integer from its hexadecimal string representation.
 *
 * @return The integral representation of the next buffered token.
 */
static int next()
{
    return strtol(strtok(NULL, DELIMITERS), NULL, 16);
}

/**
 * Reads and parses the next line from the buffered tokenizer.
 *
 * @param buffer the input buffer
 * @param cache  the simulated cache
 */
static void read(String buffer, Model data)
{
    String token = strtok(buffer, DELIMITERS);

    if (strcmp(token, "TLB") == 0)
    {
        int index = next();
        int tag = next();
        int physicalPageNumber = next();

        for (int i = 0; i < 4; i++)
        {
            if (data->tlb[index][i].physicalPageNumber == 0)
            {
                data->tlb[index][i].tag = tag;
                data->tlb[index][i].physicalPageNumber = physicalPageNumber;

                break;
            }
        }
    }
    else if (strcmp(token, "Page") == 0)
    {
        int virtualPageNumber = next();
        int physicalPageNumber = next();

        data->pages[virtualPageNumber] = physicalPageNumber;
    }
    else if (strcmp(token, "Cache") == 0)
    {
        int index = next();

        data->cache[index].tag = next();

        for (int i = 0; i < 4; i++)
        {
            data->cache[index].bytes[i] = next();
        }
    }
}

/**
 * The main entry point for the application.
 *
 * @param count the number of command-line arguments.
 * @param args  the command-line arguments. By convention, the first argument
 *              is the program name.
 * @return An exit code. This value is 0, indicating success, or 1, indicating
 *         a usage error.
 */
int main(int count, String args[])
{
    if (count < 2)
    {
        printf("Usage: project4 <input_path>\n");

        return 1;
    }

    struct Model data = {0};
    char buffer[BUFFER_SIZE];

    String fileName = args[1];
    FILE *stream = fopen(fileName, "r");
    int virtualAddress = 0;

    while (fgets(buffer, BUFFER_SIZE, stream))
    {
        read(buffer, &data);
    }

    fclose(stream);

    for (int round = 1; round <= 3; round++)
    {
        printf("Enter Virtual Address: ");

        if (!scanf("%X", &virtualAddress))
        {
            break;
        }

        int virtualPageNumber = virtualAddress >> 6;
        int tlbTag = (virtualAddress >> 8) & 0x3f;
        int tlbIndex = virtualPageNumber & 0x3;
        int cacheIndex = (virtualAddress >> 2) & 0xf;
        int cacheOffset = virtualAddress & 0x3;
        int physicalPageNumber = -1;

        for (int i = 0; i < 4; i++)
        {
            if (data.tlb[tlbIndex][i].tag == tlbTag)
            {
                physicalPageNumber = data.tlb[tlbIndex][i].physicalPageNumber;

                break;
            }
        }

        if (physicalPageNumber == -1)
        {
            physicalPageNumber = data.pages[virtualPageNumber];
        }

        if (data.cache[cacheIndex].tag != physicalPageNumber)
        {
            printf("Can not be determined\n");

            continue;
        }

        printf("%X\n", data.cache[cacheIndex].bytes[cacheOffset]);
    }

    return 0;
}
