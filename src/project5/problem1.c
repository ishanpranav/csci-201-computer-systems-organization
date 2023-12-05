// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved.
// Licensed under the MIT License.

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_SIZE 5
#define COUNT_PER_THREAD 10000
#define THREADS 10

/** Represents text as a zero-terminated sequence of characters. */
typedef char *String;

/**
 * Generates a file name and writes it to the given buffer. The size of the
 * `buffer` must be at least `BUFFER_SIZE`.
 *
 * @param buffer the buffer.
 * @param id     a unique identifier for the file.
 */
static void name(char buffer[], int id)
{
    sprintf(buffer, "%d.txt", id);
}

/**
 * Performs the parallelizable task.
 *
 * @param fileName the output file name.
 * @param min      the inclusive lower bound of the iteration.
 * @param max      the exclusive upper bound of the iteration.
 * @return `true` if the task succeeded; otherwise, `false`.
 */
static bool process(String fileName, int min, int max)
{
    remove(fileName);

    for (int i = min; i < max; i += 2)
    {
        FILE *stream = fopen(fileName, "a"); // sic

        if (!stream)
        {
            return false;
        }

        fprintf(stream, "%d\n", i);
        fclose(stream); // sic
    }

    return true;
}

/**
 * The main entry point for the application.
 *
 * @param count the number of command-line arguments.
 * @param args  the command-line arguments. By convention, the first argument
 *              is the program name.
 * @return An exit code. This value is 0, indicating success, or 1, indicating
 *         a system error.
 */
int main(int count, String args[])
{
    fprintf(stdout, "Sequential time elapsed: ");

    time_t start = time(NULL);

    if (!process("sequential.txt", 1, THREADS * COUNT_PER_THREAD))
    {
        fprintf(stderr, "Error: I/O.\n");

        return 1;
    }

    fprintf(
        stdout,
        "%lld s\nParallel time elapsed: ",
        (long long)difftime(time(NULL), start));
    fflush(stdout);

    start = time(NULL);

    for (int i = 0; i < THREADS; i++)
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            fprintf(stderr, "Error: fork() failed.\n");

            return 1;
        }

        if (pid == 0)
        {
            char buffer[BUFFER_SIZE];
            int offset = i * COUNT_PER_THREAD;

            name(buffer, i);
            process(buffer, offset + 1, offset + COUNT_PER_THREAD);

            return 0;
        }
    }

    for (int i = 0; i < THREADS; i++)
    {
        wait(NULL);
    }

    FILE *output = fopen("parallel.txt", "w");

    if (!output)
    {
        fprintf(stderr, "Error: I/O.\n");

        return 1;
    }

    for (int i = 0; i < THREADS; i++)
    {
        char buffer[BUFFER_SIZE];

        name(buffer, i);

        int c;
        FILE *input = fopen(buffer, "r");

        if (!input)
        {
            fclose(output);
            fprintf(stderr, "Error: I/O.\n");

            return 1;
        }

        while ((c = fgetc(input)) != EOF)
        {
            fputc(c, output);
        }

        fclose(input);
        remove(buffer);
    }

    fclose(output);
    fprintf(stdout, "%lld s\n", (long long)difftime(time(NULL), start));

    return 0;
}
