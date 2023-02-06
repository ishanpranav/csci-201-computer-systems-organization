#include <stdio.h>

/* Specifies an invalid color. */
#define INVALID -1

/* Specifies the message displayed when parsing fails. */
#define INVALID_MESSAGE "INVALID\n"

/**
* Converts integers representing a color into a single integer.
*
* @param r The red value, an integer between 0 (inclusive) and 256 (exclusive).
* @param g The green value, an integer between 0 (inclusive) and 256
*          (exclusive).
* @param b The blue value, an integer between 0 (inclusive) and 256
           (exclusive).
* @return -1 if any argument is out of range; otherwise, a 32-bit integer that
*         represents the color value.
*/
int from_rgb(int r, int g, int b)
{
    if (r < 0 || r > 255 ||
        g < 0 || g > 255 ||
        b < 0 || b > 255)
    {
        return INVALID;
    }

    return (r << 16) | (g << 8) | b;
}

/**
 * The main entry point for the application.
 *
 * @return 1 if the application did not receive a properly formatted number of
 *         inputs N from the standard input stream; otherwise, 0.
 */
int main()
{
    int n;

    if (!scanf("%d", &n))
    {
        return 1;
    }

    int i;

    for (i = 0; i < n; i++)
    {
        int r;
        int g;
        int b;

        if (!scanf("%d, %d, %d", &r, &g, &b))
        {
            printf(INVALID_MESSAGE);

            continue;
        }

        int value = from_rgb(r, g, b);

        if (value == INVALID)
        {
            printf(INVALID_MESSAGE);

            continue;
        }

        printf("#%06x\n", value);
    }

    return 0;
}
