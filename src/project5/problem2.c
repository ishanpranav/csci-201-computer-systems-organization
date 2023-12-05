// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved.
// Licensed under the MIT License.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include "equation.h"
#define EQUATION_MAX_LEFT 99
#define EQUATION_MAX_RIGHT 99
#define EQUATION_BUFFER_SIZE 14

/** Represents text as a zero-terminated sequence of characters. */
typedef char *String;

/** Represents a mathematical operator. */
enum Operator
{
    OPERATOR_ADD,
    OPERATOR_SUBTRACT,
    OPERATOR_MULTIPLY
};

/** Represents a mathematical equation of the form `a ~ b = c`. */
struct Equation
{
    int left;
    int right;
    enum Operator sign;
    int solution;
};

/** Represents a mathematical equation of the form `a ~ b = c`. */
typedef struct Equation *Equation;

/**
 * Randomizes the current equation. This method uses `rand()`. To generate
 * equations deterministically, call `srand(unsigned int)` before calling this
 * method.
 *
 * @param instance the `Equation` instance.
 */
void equation_randomize(Equation instance)
{
    int left = rand() % MAX_VALUE;
    int right = rand() % MAX_VALUE;
    enum Operator sign = rand() % 3;

    switch (sign)
    {
    case OPERATOR_ADD:
        instance->solution = left + right;
        break;
    case OPERATOR_SUBTRACT:
        instance->solution = left - right;
        break;
    case OPERATOR_MULTIPLY:
        instance->solution = left * right;
        break;
    }

    instance->left = left;
    instance->right = right;
    instance->sign = sign;
}

/**
 * Writes a string that represents the current equation to the given buffer.
 * The buffer size must be at least `EQUATION_BUFFER_SIZE`.
 *
 * @param instance the `Equation` instance.
 * @param buffer   the output buffer.
 */
void equation_to_string(Equation instance, char buffer[])
{
    char sign;

    switch (instance->sign)
    {
    case OPERATOR_ADD:
        sign = '+';
        break;
    case OPERATOR_SUBTRACT:
        sign = '-';
        break;
    case OPERATOR_MULTIPLY:
        sign = '*';
        break;
    }

    sprintf(
        buffer,
        "%d %c %d = %d",
        instance->left,
        sign,
        instance->right,
        instance->solution);
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
    time_t start = time(NULL);
    struct Equation equation;
    char buffer[EQUATION_BUFFER_SIZE];

    srand(start);
    equation_randomize(&equation);
    equation_to_string(&equation, buffer);
    printf("%s\n", buffer);

    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Error: fork() failed.\n");

        return 1;
    }

    if (pid == 0)
    {
        printf("%s\n", buffer);

        return 0;
    }

    return 0;
}
