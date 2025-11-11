/**
 * Write a function any(s1,s2), which returns the
 * first location in the string s1 where any character from the string s2
 * occurs, or -1 if s1 contains no characters from s2.
 */

#include <stdio.h>

int any(char s1[], char s2[])
{

    for (int x = 0; s1[x] != '\0'; x++)
    {
        for (int y = 0; s2[y] != '\0'; y++)
        {
            if (s1[x] == s2[y])
                return x;
        }
    }

    return -1;
}

int main()
{
    char a[] = "a1 test one";
    char b[] = "b2 1est one";

    int found = any(a, b);

    printf("Found at %d\n", found);
}