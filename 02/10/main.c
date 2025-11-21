/**
 * Rewrite the function lower, which converts upper case
 * letters to lower case, with a conditional expression
 * instead of if-else.
 */

#include <stdio.h>

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int ternarylower(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

int main()
{
    printf("%c\n", lower('C'));
    printf("%c\n", ternarylower('C'));
}