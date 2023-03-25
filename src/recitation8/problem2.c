#include <stdio.h>

extern int __problem2(long *xp, long *yp, long *zp);

static int problem2(long *xp, long *yp, long *zp)
{
    int result = *xp * 2;
    int cx = result * *yp;

    if (result > cx + 3)
    {
        cx = 3 * result - 12;
    }
    else if (6 > cx * 3)
    {
        cx = 2;
    }
    else
    {
        result = 3;
    }

    *xp = cx;
    *yp = result;
    result *= (5 - cx);

    return result;
}

/**
 * The main entry point for the application.
 *
 * @return An exit code.
 */
int main()
{
    long a1 = 1;
    long a2 = 1;
    long b1 = 3;
    long b2 = 3;
    long c1 = 8;
    long c2 = 8;
    int result1 = problem2(&b1, &c1, &a1);
    int result2 = __problem2(&b2, &c2, &a2);

    printf(
        "%d = %d\n%ld = %ld\n%ld = %ld\n%ld = %ld\n",
        result1, result2, a1, a2, b1, b2, c1, c2);

    return 0;
}
