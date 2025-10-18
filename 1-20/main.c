#include <stdio.h>
#define COLSPACES 8

/*
 * Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 */

int main()
{
	int c, i;

	i = 0;
	while((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			int blanks = COLSPACES - (i % COLSPACES);

			for (; blanks > 0; --blanks)
			{
				putchar(' ');
				++i;
			}
		}
		else 
		{
			putchar(c);
			if (c == '\n')
			{
					i = 0;
			}
			else
			{
					++i;
			}
		}
	}
}
