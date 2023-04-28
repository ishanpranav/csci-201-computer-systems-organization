#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "tlb_entry.h"
#define BUFFER_SIZE 1024
#define DELIMITERS ",\n"

char buffer[BUFFER_SIZE];

void readLine()
{
    int index = 0;
    char *token = strtok(buffer, DELIMITERS);

    while (token)
    {
        switch (index)
        {
        case 0:
            switch (*token)
            {
            case 'T':
                if (token[1] != 'L' || token[2] != 'B')
                {
                    return;
                }

                break;

            case 'P':
                if (token[1] != 'a' || token[2] != 'g' || token[3] != 'e')
                {
                    return;
                }
                break;

            case 'C':
                if (token[1] != 'a' || token[2] != 'c' ||
                    token[3] != 'h' || token[4] != 'e')
                {
                    return;
                }
                break;
            }
        }

        printf("%s\t", token);

        index++;
        token = strtok(NULL, DELIMITERS);
    }
}

/**
 * The main entry point for the application.
 *
 * @return An exit code. This value is always 0.
 */
int main()
{
    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        readLine();
        printf("\n");
    }

    unsigned int *virtualAddress = 0;

    printf("Enter Virtual Address: ");
    scanf("%x", virtualAddress);
}
