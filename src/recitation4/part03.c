#include <stdio.h>
#include <assert.h>

void print_in_binary(char);

void part_completed(int);

/*
The bitwise OR (a|b) operator compares two numbers on
a bit level and returns a number where the bits of that
number are turned on if either of the corresponding bits
of a and b are 1.

 a:  00101010   42
 b:  00001111   15
===============
a|b: 00101111   47

So remember for every given bit in a and b
  0 | 0 = 0
  0 | 1 = 1
  0 | 1 = 1
  1 | 1 = 1
*/

int main()
{
    /* TODO: Initialize a, b, c so that the tests pass */
    char bits = 0b1000; // Binary 8

    char a;
    char b;
    char c;

    assert((a | bits) == 0b1000);
    assert((b | bits) == 0b1101);
    assert((c | bits) == 0b1111);

    part_completed(3);

    return 0;
}