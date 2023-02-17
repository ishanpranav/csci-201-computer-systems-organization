#include <stdio.h>
#include <assert.h>

void print_in_binary(char);

void part_completed(int);

/*
The bitwise not operator (~a) just flips all of
the bits in a single number.
*/

int main()
{
    /*
      For positive numbers, this is equivalent to
      adding one to the number and making it negative
      in decimal.
    */
    print_in_binary(~0b1111); // Binary 15
    print_in_binary(~0b0000); // Binary 0

    /*
      For negative numbers, this is equivalent to
      adding one to the number and making it positive
      in decimal.
    */
    print_in_binary(  2);
    print_in_binary(~-2);
    print_in_binary( 4);
    print_in_binary(~-4);

    /* TODO: initialize x and y such that the assertions pass
       Hint: you can "look" at the bits of -1 using the print_in_binary function.
    */
    char x;
    assert(~1 == x);
    char y;
    assert(~-1 == y);

    part_completed(5);

    return 0;
}
