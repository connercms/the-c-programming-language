/**
 * Write a function setbits(x,p,n,y) that returns x
 * with the n bits that begin at position p set to
 * the rightmost n bits of y, leaving the other bits
 * unchanged.
 */

#include <stdio.h>

int setbits(unsigned int x, int p, unsigned int n, int y);

int main()
{
    int test1 = setbits(170, 4, 3, 15);
    printf("Test: expected %d, result %d\n", 190, test1);
    return 0;
}

/* Return x with the n bits beginning at position p set to rightmost n bits of y */
int setbits(unsigned int x, int p, unsigned int n, int y)
{
    // Create the base mask by shifting an all 1-bit mask left N bits,
    // then inverting it so the rightmost 0 bits become 1-bits instead.
    unsigned int mask = ~(~0u << n) << (p + 1 - n);
    // To create the x mask, shift it into the requested position,
    // then invert. Ex 0000 0111 -> 0111 0000 -> 1000 1111

    unsigned int xmask = ~mask;

    // Apply the x mask
    unsigned int maskedx = x & xmask;
    // Apply the base mask to get the rightmost n bits of y,
    // then shift it into position to line it up with masked x
    unsigned int maskedy = (y & mask) << (p + 1 - n);

    unsigned int result = maskedx | maskedy;

    return result;
}
