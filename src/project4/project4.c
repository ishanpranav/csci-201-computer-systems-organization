// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved.
// Licensed under the MIT License.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 32
#define DELIMITERS ",\n"
#define DEFAULT_FILE_NAME "Project4Input (1) (1) (1).txt"

typedef char *String;
typedef unsigned char Byte;

typedef struct TlbEntry
{
    int tag;
    int physicalPageNumber;
} TlbEntry;

typedef struct CacheLine
{
    int tag;
    Byte bytes[4];
} CacheLine;

char buffer[BUFFER_SIZE];
int pages[16];
CacheLine cacheLines[16];
TlbEntry tlbSets[4][4];

static int nextInt()
{
    String token = strtok(NULL, DELIMITERS);

    return strtol(token, NULL, 16);
}

static bool read()
{
    String token = strtok(buffer, DELIMITERS);

    if (!strcmp(token, "TLB"))
    {
        int index = nextInt();
        int tag = nextInt();
        int physicalPageNumber = nextInt();

        for (int i = 0; i < 4; i++)
        {
            if (tlbSets[index][i].physicalPageNumber == 0)
            {
                tlbSets[index][i].tag = tag;
                tlbSets[index][i].physicalPageNumber = physicalPageNumber;

                break;
            }
        }
    }
    else if (!strcmp(token, "Page"))
    {
        int virtualPageNumber = nextInt();
        int physicalPageNumber = nextInt();

        pages[virtualPageNumber] = physicalPageNumber;
    }
    else if (!strcmp(token, "Cache"))
    {
        int index = nextInt();

        cacheLines[index].tag = nextInt();

        for (int i = 0; i < 4; i++)
        {
            cacheLines[index].bytes[i] = nextInt();
        }
    }

    return true;
}

static void printError()
{
    printf("Can not be determined\n");
}

static void dumprt()
{
    for (int i = 0; i < 4; i++)
    {
        printf("TLB\t");

        for (int j = 0; j < 4; j++)
        {
            printf("%02X %02X %02X\t", i, tlbSets[i][j].tag, tlbSets[i][j].physicalPageNumber);
        }

        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 16; i++)
    {
        printf("Page\t%X %02X\n", i, pages[i]);
    }

    printf("\n");

    for (int i = 0; i < 16; i++)
    {
        printf("Cache\t%X %02X", i, cacheLines[i].tag);

        for (int j = 0; j < 4; j++)
        {
            printf(" %02X", cacheLines[i].bytes[j]);
        }

        printf("\n");
    }
}

/**
 * The main entry point for the application.
 *
 * @return An exit code. This value is always 0.
 */
int main(int count, String args[])
{
    String fileName;

    if (count > 1)
    {
        fileName = args[1];
    }
    else
    {
        fileName = DEFAULT_FILE_NAME;
    }

    printf("Reading database from \"%s\"... ", fileName);

    FILE *streamReader = fopen(fileName, "r");
    int virtualAddress = 0;

    while (fgets(buffer, BUFFER_SIZE, streamReader) && read())
        ;

    fclose(streamReader);

    printf("Done.\n");
    dumprt();

    for (int round = 1; round <= 3; round++)
    {
        printf("Enter Virtual Address: ");

        if (!scanf("%X", &virtualAddress))
        {
            break;
        }

        int tlbTag = (virtualAddress >> 8) & 0x3f;
        int tlbIndex = (virtualAddress >> 6) & 0x3;
        int cacheIndex = (virtualAddress >> 2) & 0xf;
        int cacheOffset = virtualAddress & 0x3;
        int physicalPageNumber = -1;

        for (int i = 0; i < 4; i++)
        {
            if (tlbSets[tlbIndex][i].tag == tlbTag)
            {
                physicalPageNumber = tlbSets[tlbIndex][i].physicalPageNumber;

                break;
            }
        }

        if (physicalPageNumber == -1)
        {
            printError();

            continue;
        }

        if (cacheLines[cacheIndex].tag != physicalPageNumber)
        {
            printError();
            
            continue;
        }

        printf("%X\n", cacheLines[cacheIndex].bytes[cacheOffset]);
    }

    return 0;
}
