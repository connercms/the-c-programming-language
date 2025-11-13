/**
 * Write a function invert(x,p,n) that returns x with the
 * n bits that begin at position p inverted
 * (i.e., 1 changed into 0 and vice versa),
 * leaving the other unchanged.
 */

#include <stdio.h>

int invert(unsigned int x, unsigned int p, unsigned int n);

int main()
{
    printf("Test: expected %d, result %d\n", 63, invert(48, 3, 4));
    printf("Test: expected %d, result %d\n", 48, invert(63, 3, 4));
    return 0;
}

int invert(unsigned int x, unsigned int p, unsigned int n)
{
    unsigned int mask = ~(~0 << n) << (p + 1 - n);

    return x ^ mask;
}