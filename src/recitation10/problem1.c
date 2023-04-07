#include <stdio.h>

extern int __problem1(long *xp, long *yp, long *zp);

static int problem1(long *xp, long *yp, long *zp)
{
    long t0 = *xp * 2;
    long t1 = *yp * t0;

    while (t1 > t0)
    {
        t1 *= (t1 - 4);
        t0 *= 23;
    }

    *xp = t1;
    *yp = t0;

    return (5 - t1) * t0;
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
    int result1 = problem1(&a1, &b1, &c1);
    int result2 = __problem1(&a2, &b2, &c2);

    printf(
        "%d = %d\n%ld = %ld\n%ld = %ld\n%ld = %ld\n",
        result1, result2, a1, a2, b1, b2, c1, c2);

    return 0;
}
