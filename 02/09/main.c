/**
 * In a two's complement number system, x &= (x-1)
 * deletes the rightmost 1-bit in x. Explain why.
 * Use this observation to write a faster version of bitcount.
 *
 * Explanation: In a two's complement number system, subtraction
 * is performed by adding the two's complement of the subtrahend to
 * the minuend, and handling the carry out bit.
 *
 * This is done by inverting all the bits of the subtrahend and adding
 * one (this is finding the twos complement).
 *
 * x &= (x-1) deletes the rightmost bit because it's inverting only the rightmost
 * bit of x, then AND'ing the result and x together. The inverted rightmost bit and
 * the original rightmost bit will never match, therefore it will always result in the
 * bit being deleted.
 */

#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    // Compares rightmost bit of x and 1.
    // If the result is 1 (true), it adds to the counter.
    // Shift bits of x right until and repeat until x is 0.
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;

    return b;
}

int fasterbitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; b++)
        x &= x - 1;

    return b;
}

int main()
{
    printf("%u\n", bitcount(1));
    printf("%u\n", fasterbitcount(1));

    printf("%u\n", bitcount(5));
    printf("%u\n", fasterbitcount(5));

    printf("%u\n", bitcount(10));
    printf("%u\n", fasterbitcount(10));

    printf("%u\n", bitcount(13));
    printf("%u\n", fasterbitcount(13));
}
