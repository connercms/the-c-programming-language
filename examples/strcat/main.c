#include <stdio.h>

/**
 * strcat: concatenate t to the end of s; s must be big enough
 */
void str_cat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    /* find the end of s */
    while (s[i] != '\0')
        i++;

    /* copy t*/
    while ((s[i++] = t[j++]) != '\0')
        ;
}

int main()
{
    char a[] = "Hello, my name ";
    char b[] = "is Conner Shannon";

    str_cat(a, b);

    printf("%s", a);
}