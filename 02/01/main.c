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
#include <math.h>

int main()
{
    printf("Char (unsigned): %d to %d\n", 0, UCHAR_MAX);
    printf("Char bit: %f\n", pow(2, CHAR_BIT) - 1);
    printf("Char (signed): %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Short (unsigned): %d to %d\n", 0, USHRT_MAX);
    printf("Short (signed): %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Long (unsigned): %d to %ld\n", 0, ULONG_MAX);
    printf("Long (signed): %ld to %ld\n", LONG_MIN, LONG_MAX);

    return 0;
}