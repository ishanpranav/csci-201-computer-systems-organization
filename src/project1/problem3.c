// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved. 
// Licensed under the MIT License. 

#include <stdio.h>

/**
 * The main entry point for the application.
 *
 * @return An exit code. This value is always 0, indicating success.
 */
int main()
{
    int n;

    // Scan values in the form N until N is 0

    while (scanf("%d", &n) && n)
    {
        int j = 0;
        int an = 0;
        int bn = 0;
        char isA = 1;

        // Destructively iterate over the bits of N (right-shift until N is 0)

        while (n)
        {
            // If N is even (the least significant bit is 1)

            if (n & 1)
            {
                if (isA)
                {
                    // Add a one at the j-th bit of 'an'

                    an |= 1 << j;
                    isA = 0;
                }
                else
                {
                    // Add a one at the j-th bit of 'bn'

                    bn |= 1 << j;
                    isA = 1;
                }
            }

            j++;
            n >>= 1;
        }

        printf("%d %d\n", an, bn);
    }

    return 0;
}
