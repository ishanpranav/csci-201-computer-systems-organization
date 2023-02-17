#include <stdio.h>
#include <assert.h>

void print_in_binary(char);

void part_completed(int);

/*
Bitwise operators can also aid you in creating masks.
*/

/* TODO: Make a function flip_bit that takes the inputs (n, number)
         and then returns the number with the nth bit from the right flipped.
         (with the ones bit being the 0th bit)*/
int flip_bit(int n, int number)
{
    /*  
    n - is the nth bit to be flipped and indexing is zero based
    number - The number whose nth bit needs to be flipped
    Hint: Use a bit shift in order to get your mask into place
             and then use the XOR operator in order to flip the desired bit. */  
    return 0;  //modify to return your calculated value 
}

int main()
{
   //flip_bit(1, 0);
    assert(flip_bit(0, 0) == 1);
    assert(flip_bit(1, 0) == 2);
    assert(flip_bit(3, 10) == 2);
    assert(flip_bit(3, 3) == 11);
    assert(flip_bit(4, 0) == 16);

    part_completed(10);

    return 0;
}
