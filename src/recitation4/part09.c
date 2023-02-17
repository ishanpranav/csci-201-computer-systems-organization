#include <stdio.h>
#include <assert.h>

void print_in_binary(char);

void part_completed(int);

/*
The bitwise XOR Operator is useful for flipping bits.
*/

int main()
{
    /* TODO: Use a mask and the bitwise XOR operator in order
       to flip the first four bits of a. */
    short a = 0b1010;

    /* Initialize 'mask' with the right value */
    short mask;

    assert((a ^ mask) == 0b0101);

    part_completed(9);

    return 0;
}