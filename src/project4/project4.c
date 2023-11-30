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
} CacheLine;

/** Represents a simulated cache. */
struct Cache
{
    int pages[16];
    struct TlbEntry tlb[4][4];
    struct CacheLine lines[16];
};

/** Represents a simulated cache. */
typedef struct Cache *Cache;

/**
 * Retrieves the next token from the buffered tokenizer, converted to an
 * integer from its hexadecimal string representation.
 *
 * @return The integral representation of the next buffered token.
 */
static int next()
{
    String token = strtok(NULL, DELIMITERS);

    return strtol(token, NULL, 16);
}

/**
 * Reads and parses the next line from the buffered tokenizer.
 *
 * @param buffer the input buffer
 * @param cache  the simulated cache
 */
static void read(String buffer, Cache cache)
{
    String token = strtok(buffer, DELIMITERS);

    if (strcmp(token, "TLB") == 0)
    {
        int index = next();
        int tag = next();
        int physicalPageNumber = next();

        // Brief linear search to find an empty position in the TLB set

        for (int i = 0; i < 4; i++)
        {
            if (cache->tlb[index][i].physicalPageNumber == 0)
            {
                cache->tlb[index][i].tag = tag;
                cache->tlb[index][i].physicalPageNumber = physicalPageNumber;

                break;
            }
        }
    }
    else if (strcmp(token, "Page") == 0)
    {
        // Index into the page table directly

        int virtualPageNumber = next();
        int physicalPageNumber = next();

        cache->pages[virtualPageNumber] = physicalPageNumber;
    }
    else if (strcmp(token, "Cache") == 0)
    {
        // Index into the cache directory

        int index = next();

        cache->lines[index].tag = next();

        for (int i = 0; i < 4; i++)
        {
            cache->lines[index].bytes[i] = next();
        }
    }
}

/**
 * The main entry point for the application.
 *
 * @param count the number of command-line arguments
 * @param args the command-line arguments. By convention, the first argument is
 *             the program name.
 * @return An exit code. This value is always 0.
 */
int main(int count, String args[])
{
    if (count < 2)
    {
        printf("Usage: project4 <input_path>\n");

        return 1;
    }

    struct Cache cache;
    char buffer[BUFFER_SIZE];

    String fileName = args[1];
    FILE *streamReader = fopen(fileName, "r");
    int virtualAddress = 0;

    while (fgets(buffer, BUFFER_SIZE, streamReader))
    {
        read(buffer, &cache);
    }

    fclose(streamReader);

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

        // Brief linear search to find a matching tag in the TLB set

        for (int i = 0; i < 4; i++)
        {
            if (cache.tlb[tlbIndex][i].tag == tlbTag)
            {
                physicalPageNumber = cache.tlb[tlbIndex][i].physicalPageNumber;

                break;
            }
        }

        if (physicalPageNumber == -1)
        {
            // No matching tag discovered in the TLB
            // Index into the virtual page table instead

            physicalPageNumber = cache.pages[virtualPageNumber];
        }

        if (cache.lines[cacheIndex].tag != physicalPageNumber)
        {
            // Incorrect tag discovered in the cache

            printf("Can not be determined\n");

            continue;
        }

        // No issues encountered

        printf("%X\n", cache.lines[cacheIndex].bytes[cacheOffset]);
    }

    return 0;
}
