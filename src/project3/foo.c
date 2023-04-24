// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved.
// Licensed under the MIT License.

#include "foo.h"

/**
 * Performs a mystery function on two arguments and returns the result.
 *
 * @param a the first argument
 * @param b the second argument
 * @return The result of the function.
 */
long foo(long a, long b)
{
    return (a * -43) + (b * 188); // lea (%rdi, %rdi, 2), %rax
                                  // lea (%rdi, %rax, 4), %rax
                                  // shl $2, %rax
                                  // lea (%rsi, %rsi, 2), %rcx
                                  // mov %rcx, %rdx
                                  // shl $5,   %rdx
                                  // sub %rcx, %rdx
                                  // add %rdx, %rax
                                  // sub %rdi, %rsi
                                  // lea (%rsi, %rsi, 2), %rdx
                                  // shl $5,   %rdx
                                  // sub %rsi, %rdx
                                  // add %rdx, %rax
                                  // retq
}
