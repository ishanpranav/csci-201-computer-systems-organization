#include <stdio.h>
#include <assert.h>
#include "util.h"

/*
The most basic bitwise operators are the left and right shift bitwise operators.
These operators work by shifting the bits over by a designated number
'b' of slots. Lets take a look at how these shifts work.

The block below shows how these operators work on the bit level.
Note that in the diagram the shifts or 'b',  is usually written
as a decimal integer.

Left Bit Shift <<
00000001 << 2 = 00000100 (1 << 2 = 4)
00000101 << 3 = 00101000 (5 << 3 = 40)

Right Bit Shift >>
000010100 >> 3 = 00000010 (20 >> 3 = 2)
000000010 >> 2 = 00000000 (2 >> 2 = 0)

Note that shifting more than the size of the type is undefined behavior.

In the examples below, we use char as a type to be able to
use only 8 bits.
*/

int left_shift(int shift_me, int b)
{

    /* TODO: implement me
      - provide the code,
      - replace 0 in the return statement with the correct value
    */
    return 0;
}

int right_shift(int shift_me, int b)
{
    /* TODO: implement me
      - provide the code,
      - replace 0 in the return statement with the correct value
    */

    return 0;
}

int main()
{
    assert(left_shift(1, 2) == 4);
    assert(left_shift(5, 3) == 40);

    /* TODO: initialize x so that line below succeeds */

    int x;
    assert(left_shift(4, 3) == x);
    assert(right_shift(20, 3) == 2);
    assert(right_shift(2, 2) == 0);

    /* TODO: initialize y so that line below succeeds */

    int y;
    assert(right_shift(16, 3) == y);

    /*
    Note that you can use binary numbers explicitly in your code with the
    following notation.
    */
    
    assert(left_shift(0b00000001, 2) == 4);
    assert(right_shift(0b01000000, 3) == 8);

    /*
    And I've provided you with a method to see the binary representation of
    any char.
    */

    print_in_binary(12);

    /*
    But remember there are two types of shifts?
    Logical, which is what we have above and
    Arithmetic, which happens when we right shift
    numbers (noticable for negative numbers, especially).
    */

    print_in_binary(0b10000000);
    print_in_binary(right_shift(0b10000000, 1));
   
    /* What happened at the line above? */

    /* TODO: initialize z so that line below succeeds */
   
    int z;
    assert(right_shift(0b10000000, 1) == z);

    part_completed(1);

    return 0;
}
