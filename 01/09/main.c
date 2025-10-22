#include <stdio.h>

/*
 * Write a program to copy its input to its
 * output, replacing each string of one or more blanks by
 * a single blank
 */
int main()
{
	int c, blankctr;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (blankctr == 0)
				putchar(c);

			++blankctr;	
		}
		if (c != ' ')
		{
			blankctr = 0;	
			putchar(c);
		}
		
	}	
	return 0;
}
