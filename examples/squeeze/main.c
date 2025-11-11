#include <stdio.h>

/**
 * Remove all characters c from string s
 */
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            // j is only incremented when s[i] is not c
            // so when s[i] does equal c, j is not incremented,
            // and the next not c char will be moved to j
            s[j++] = s[i];
}

int main()
{
    char s[] = "my name is conner shannon";
    squeeze(s, 'n');
    printf("%s", s);
    return 0;
}
