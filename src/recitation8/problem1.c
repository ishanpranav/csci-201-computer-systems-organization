#include <stdio.h>

extern int __problem1(long *a, long *b, long *c);

static int problem1(long *a, long *b, long *c)
{
    int result = *a;
    int cx = (*b * 3) * result;

    while (cx > result)
    {
        int two = result * 2;

        cx = result + two;
        result = two;
    }

    return result;
}

/**
 * The main entry point for the application.
 *
 * @return An exit code.
 */
int main()
{
    long a1 = 3;
    long a2 = 3;
    long b1 = 8;
    long b2 = 8;
    long c1 = 1;
    long c2 = 1;
    
    printf("%d = %d\n", problem1(&a1, &b1, &c1), __problem1(&a2, &b2, &c2));

    return 0;
}
