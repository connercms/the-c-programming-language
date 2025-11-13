/**
 * Write a function rightrot(x,n) that
 * returns the value of the integer x rotated to the right by
 * n bit positions.
 */

#include <stdio.h>

__uint8_t rightrot(__uint8_t x, int n);

int main()
{
    __uint8_t result = rightrot(47, 3);
    printf("Test: expected %u, result %u\n", 229U, result);
    return 0;
}

__uint8_t rightrot(__uint8_t x, int n)
{
    // Get the number of bits in x
    __uint8_t w = sizeof(x) * 8;

    // Create a mask to capture the rightmost n bits of x
    __uint8_t mask = ~(~0 << n);
    __uint8_t capturedbits = x & mask;

    // Shift x by n bits (this pads the leftmost bits as 0s)
    __uint8_t shiftedx = x >> n;

    // Shift the captured rightmost n bits of x to the left
    __uint8_t rbits = capturedbits << (w - n);

    // OR together to get final result
    __uint8_t result = shiftedx | rbits;

    return result;
}