// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved.
// Licensed under the MIT License.

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#define EQUATION_MAX_LEFT 9
#define EQUATION_MAX_RIGHT 9

/** Represents text as a zero-terminated sequence of characters. */
typedef char *String;

/** Represents a mathematical equation of the form `a ~ b = c`. */
typedef struct Equation *Equation;

pid_t pid;
int solution;
int incorrect;
int missed;
bool timeOut;

/**
 * Handles an interrupt signal (SIGINT) sent from a child process.
 *
 * @param signal the signal code.
 */
void sigint(int signal)
{
    kill(pid, SIGKILL);

    timeOut = true;
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
    int length;

    signal(SIGINT, sigint);
    srand(time(NULL));
    printf("How many questions in the quiz? ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++)
    {
        timeOut = false;

        int left = rand() % (EQUATION_MAX_LEFT + 1);
        int right = rand() % (EQUATION_MAX_RIGHT + 1);
        char symbol = 0;

        if (left < right)
        {
            int swap = left;

            left = right;
            right = swap;
        }

        switch (rand() % 3)
        {
        case 0:
            solution = left + right;
            symbol = '+';
            break;
        case 1:
            solution = left - right;
            symbol = '-';
            break;
        case 2:
            solution = left * right;
            symbol = '*';
            break;
        default:
            return 1;
        }

        pid = fork();

        if (pid < 0)
        {
            fprintf(stderr, "Error: fork() failed.\n");

            return 1;
        }

        if (pid == 0)
        {
            String args[] = {"problem2Timer", NULL};

            execv(args[0], args);
            fprintf(stderr, "Error: execv() failed.\n");

            return 1;
        }

        int response = solution + 1;

        while (response != solution)
        {
            printf("What is %d %c %d?\n", left, symbol, right);
            scanf("%d", &response);

            if (timeOut)
            {
                missed++;

                while (response)
                {
                    scanf("%d", &response);
                }
                
                break;
            }

            if (response == solution)
            {
                printf("Correct!\n");
                kill(pid, SIGKILL);

                continue;
            }

            incorrect++;

            printf("Incorrect, please try again.\n");
        }
    }

    printf(
        "\n- Results -\nCorrect:\t%d/%d\nIncorrect:\t%d/%d\nMissed:\t\t%d/%d\n",
        length - incorrect - missed,
        length,
        incorrect,
        length,
        missed,
        length);

    return 0;
}
