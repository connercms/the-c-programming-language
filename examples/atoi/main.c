#include <stdio.h>

int main()
{
    char s[5] = "38465";
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    {
        printf("n@%d-1: %d, ", i, n);
        n = 10 * n + (s[i] - '0');
        printf("n@%d-2: %d\n", i, n);
    }

    return 0;
}