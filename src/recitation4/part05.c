#include <stdio.h>
#include <assert.h>
#include "util.h"

/**
 * The main entry point for the application.
 * 
 * @return An exit code. This value is 0 if all assertions succeed. 
 */
int main()
{
    print_in_binary(~0b1111);
    print_in_binary(~0b0000);
    print_in_binary(2);
    print_in_binary(~-2);
    print_in_binary(4);
    print_in_binary(~-4);

    char x;
    
    print_in_binary(1);
    print_in_binary(-1);

    assert(~1 == x);
    
    char y;
    
    assert(~-1 == y);

    part_completed(5);

    return 0;
}
