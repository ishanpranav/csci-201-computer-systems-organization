#include "bar.h"

long bar(long a, long b)
{
    long rdx = a;
    long result = 0;
    long rcx = 11 * a;

    a = b * 16;

    rcx += b * 2 - a + 1;

    while (rdx <= b)
    {
        rdx++;
        result += rcx;
    }

    return result;
}
