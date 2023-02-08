#include <stdio.h>

/**
 * The main entry point for the application.
 *
 * @return An exit code. This value is always 0, indicating success.
 */
int main()
{
    int n;

    while (scanf("%d", &n) && n)
    {
        int i = 1;
        int j = 0;
        int an = 0;
        int bn = 0;

        while (n)
        {
            if (n & 1)
            {
                if (i)
                {
                    an |= 1 << j;
                    i = 0;
                }
                else
                {
                    bn |= 1 << j;
                    i = 1;
                }
            }

            j++;
            n >>= 1;
        }

        printf("%d %d\n", an, bn);
    }

    return 0;
}
