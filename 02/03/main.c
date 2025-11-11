/**
 * Write a function htoi (s),
 * which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9,
 * a through f, and A through F.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char s[]);

int main()
{
    printf("%d\n", htoi("0x1f"));
    printf("%d\n", htoi("0X1f"));

    printf("%d\n", htoi("0Xa"));
    printf("%d\n", htoi("0XA"));
    printf("%d\n", htoi("0X1ffa"));
}

int htoi(char s[])
{
    int i = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    int n = 0;

    for (; isdigit(s[i]) ||
           (s[i] >= 'a' && s[i] <= 'f') ||
           (s[i] >= 'A' && s[i] <= 'F');
         ++i)
    {
        int d = 0;

        if (isdigit(s[i]))
        {
            d = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            d = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            d = s[i] - 'A' + 10;
        }

        n = 16 * n + d;
    }

    return n;
}