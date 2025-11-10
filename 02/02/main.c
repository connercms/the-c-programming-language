
/**
 * for (i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 * {
 *    s[i] = c;
 * }
 *
 * Write a for loop equivalent to the above without using && or ||.
 *
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);

int main()
{
    char s[MAXLINE];
    get_line(s, MAXLINE);
    printf("%s", s);

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i = 0, LOOP = 1;

    while (LOOP)
    {

        c = getchar();
        if (c == EOF)
        {
            LOOP = 0;
        }
        else if (c == '\n')
        {
            LOOP = 0;
        }
        else
        {
            s[i] = c;
            ++i;
        }
    }

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}