#include <stdio.h>
#include <assert.h>

void print_in_binary(char);

void part_completed(int);

/*
A bitmask is just a variable that aids you with bitwise operations.

A bitmask can help you turn specific bits on and off or just collect
data from a certain part of a bit vector.

Using the & operator with a mask is the easiest way certain to turn bits off.
*/

int main()
{
    short a = 0b101010101;

    /* TODO: Initialize 'mask' such that when it is AND'ed with 'a'
       the results is the last three bits of 'a'
       (e.g. the 1's 2's and 4's bit). */
    short mask;

    print_in_binary( (a & mask) );
    assert((a & mask) == 0b101);

    part_completed(6);

    return 0;
}
