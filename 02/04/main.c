/**
 * Write an alternate version of squeeze(s1,s2) that
 * deletes each character in s1 that matches any character
 * in the string s2.
 */

#include <stdio.h>

/**
 * Removes all characters from s1 that exist in s2
 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    // loop through chars in array s1
    // loop through chars in array s2
    // if s2 char == s1 char, remove from s1
    for (i = j = 0; s1[i] != '\0'; i++)
    {
        int remove = 0;
        for (k = 0; s2[k] != '\0'; k++)
        {
            if (s1[i] == s2[k])
            {
                remove = 1;
            }
        }

        if (!remove)
        {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0';
}

int main()
{
    char a[] = "Today is a Tuesday.";
    char b[] = "My name is John.";

    squeeze(a, b);

    printf("%s", a);

    return 0;
}