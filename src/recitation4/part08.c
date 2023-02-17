#include <stdio.h>
#include <assert.h>

void print_in_binary(char);

void part_completed(int);

/*
Using the >> and << bitwise operators can aid us in trying
to extract a particular bit or a sequence of bits in a bit vector.
*/

int main()
{
    /*
    TODO: Use a bit shifts and a mask in order to get bit
    value of the 8's and 4's bits in 'a' and 'b' (these are the third and fourth bits from the right).

    Hint: Use a right shift to get 'a' and 'b' into the desired position
          and then bitwise AND it with your 'mask' to get the result.
    */

    int a = 0b00001011010111; 
    int b = 0b11001001001101; 

    /* Initialize 'mask', 'bita' and 'bitb' with the right values */
    int mask;   //this should be just a number in binary

    int bita;    //this should be an expression involving a, shift operator and mask variable

    int bitb;    //this should be an expression involving b, shift operator and mask variable

    assert(bita == 0b01);
    assert(bitb == 0b11);

    part_completed(8);

    return 0;
}
