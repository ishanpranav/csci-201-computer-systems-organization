#include <stdio.h>
#include <assert.h>

void print_in_binary(char);

void part_completed(int);

/*
The XOR(a^b) or Exclusive Or operator compares two numbers on
a bit level and returns a number where the bits of that number
are turned on if either of the corresponding bits of a and b
are 1 but not both.

 a:  00101010   42
 b:  00001111   15
===============
a^b: 00100101   37

So remember for every given Bit in a and b
  0 ^ 0 = 0
  0 ^ 1 = 1
  1 ^ 0 = 1
  1 ^ 1 = 0
*/

int main()
{
    /* TODO: Initialize a, b, c so that the tests pass */
    char bits = 0b1010; // Binary 10

    char a;
    char b;
    char c;

    assert((a ^ bits) == 0b1000);
    assert((b ^ bits) == 0b1101);
    assert((c ^ bits) == 0b1111);

    part_completed(4);

    return 0;
}