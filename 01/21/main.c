#include <stdio.h>
#define TABSTOP 8

/*
 * A program to replace strings of spaces with the minimum number of tabs 
 * and blanks to achieve the same spacing. Blanks are output as an underscore
 * so the result is more evident.
 */

int main()
{
	int c, i, blanks;

	i = blanks = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			++blanks;
			if (blanks > 0 && ((i + blanks) % TABSTOP == 0))
			{
				putchar('\t');
				i+=blanks;
				blanks = 0;
			}
			
		}
		else if (c == '\n')
		{
			blanks = 0;
			i = 0;
			putchar(c);
		}
		else 
		{
			while (blanks > 0)
			{
					putchar('_');
					--blanks;
					++i;
			}
			putchar(c);
			++i;
		}
	}
}
