#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#define N 1000000000

/** Represents the current index. */
long i;

/** Represents the number of primes discovered. */
long count = N - 1;

/** Represents the number of primes discovered at the last interrupt. */
long lastCount;

/**
 * Handles an interrupt signal (SIGINT)
 *
 * @param signal the signal code. This value is always `SIGINT`.
 */
void sigint(int signal)
{
    printf("Primes since last SIGINT: %ld\nCurrent: %ld\nTotal: %ld\n",
           count - lastCount,
           i,
           count);
}

/**
 * The main entry point for the application.
 *
 * @return An exit code. This value is always 0, indicating success.
 */
int main()
{
    signal(SIGINT, sigint);

    bool *composites = calloc((N - 1), sizeof *composites);

    if (!composites)
    {
        fprintf(stderr, "Error: Out of memory.\n");

        return 1;
    }

    long end = (N + 1) / 2;

    for (i = 2; i <= end; i++)
    {
        if (composites[i - 2])
        {
            continue;
        }

        for (long j = i * 2; j <= N; j += i)
        {
            if (composites[j - 2])
            {
                continue;
            }

            composites[j - 2] = true;
            count--;
        }
    }

    printf("%ld\n", count);
}
