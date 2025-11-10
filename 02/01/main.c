/**
 * Write a program to determine the ranges
 * of char, short, int, and long variables, both signed and
 * unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder
 * if you compute them: determine the ranges of the various floating-point types.
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

int main()
{
    printf("LIMITS.H\n");
    printf("CHAR_MIN %d, CHAR_MAX %d\n", CHAR_MIN, CHAR_MAX);
    printf("UCHAR_MIN 0, UCHAR_MAX %d\n", UCHAR_MAX);
    printf("SHORT_MIN %d, SHORT_MAX %d\n", SHRT_MIN, SHRT_MAX);
    printf("USHORT_MIN 0, USHORT_MAX %d\n", USHRT_MAX);
    printf("INT_MIN %d, INT_MAX %d\n", INT_MIN, INT_MAX);
    printf("UINT_MIN 0, UINT_MAX %d\n", UINT_MAX);
    printf("LONG_MIN %ld, LONG_MAX %ld\n", LONG_MIN, LONG_MAX);
    printf("ULONG_MIN 0, ULONG_MAX %ld\n", ULONG_MAX);
    printf("FLOAT_MIN %.0f, FLOAT_MAX %.0f\n", FLT_MIN, FLT_MAX);
    printf("DOUBLE_MIN %.0f, DOUBLE_MAX %.0f\n", DBL_MIN, DBL_MAX);

    putchar('\n');

    /**
     * To compute signed, start at 1 and add 1 until overflow.
     * This is the min.
     * Subtract one to overflow back to the max.
     */
    printf("COMPUTED\n");

    char c = 1;
    while (c > 0)
        ++c;
    printf("CHAR_MIN %d, CHAR_MAX %d\n", c, (char)(c - 1));
    printf("UCHAR_MIN 0, UCHAR_MAX %d\n", -(c * 2) - 1);

    short s = 1;
    while (s > 0)
        ++s;
    printf("SHORT_MIN %d, SHORT_MAX %d\n", s, (short)(s - 1));
    printf("USHORT_MIN 0, USHORT_MAX %d\n", -(s * 2) - 1);

    int i = 1;
    while (i > 0)
        ++i;
    printf("INT_MIN %d, INT_MAX %d\n", i, (int)(i - 1));
    printf("UINT_MIN 0, UINT_MAX %d\n", -(i * 2) - 1);

    /**
     * This one takes an absurdly long time... not sure how to fix at this point.
     */
    printf("ULONG computation not included due to excessive computation time.\n");
    // long l = 1;
    // while (l > 0)
    //     ++l;
    // printf("LONG_MIN %ld, LONG_MAX %ld\n", l, (long)(l - 1));
    // printf("ULONG_MIN 0, ULONG_MAX %ld\n", -(l * 2) - 1);

    return EXIT_SUCCESS;
}
