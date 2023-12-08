#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define N 500000

/**
 * The main entry point for the application.
 *
 * @return An exit code. This value is always 0, indicating success.
 */
int main()
{
    bool *composites = calloc((N - 1), sizeof *composites);

    if (!composites)
    {
        fprintf(stderr, "Error: Out of memory.\n");

        return 1;
    }

    long end = (N + 1) / 2;

    for (long i = 2; i <= end; i++)
    {
        if (composites[i - 2])
        {
            continue;
        }

        for (long j = i * 2; j <= N; j += i)
        {
            composites[j - 2] = true;
        }
    }

    long count = 0;

    for (long i = 2; i <= N; i++)
    {
        if (composites[i - 2])
        {
            continue;
        }

        count++;
    }

    printf("%ld\n", count);
}
