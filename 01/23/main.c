/*
 * A program to remove all comments from a C program. Handle quoted strings
 * and character constants properly. C comments do not nest.
 */

#include <stdio.h>
#define OUT 0
#define IN 1

int main()
{
	int c, state, secondchar, tabs;
	state = OUT;

	while ((c = getchar()) != EOF)
	{
		// if c is the start of a comment
		if (c == '/')
		{
			int nextc = getchar(); // fetch and evaluate the next char

			if (state == OUT)
			{
				// if it is the second char of a comment block, set state
				if (nextc == '/' || nextc == '*')
				{
					state = IN;
					secondchar = nextc;
				}
				// else just print both characters
				else
				{
					putchar(c);
					putchar(nextc);
				}
			}
			else if (state == IN)
			{
				// if we are in a comment, we need to check if comment is a multiline comment
				// and if next char is going to end the comment
				if (nextc == '*' && secondchar == '*')
				{
					state = OUT;
					tabs = 0;
				}
			}
		}
		else if (c == '\t')
		{
			// Have to count tabs because a comment could be tabbed also
			// and resuming printing after a comment without resetting tab
			// count would make the next line over-tabbed
			++tabs;
		}
		else if (c == '*')
		{
			// get and eval next char to see if multiline comment is being broken
			int nextc = getchar();
			if (state == IN && nextc == '/')
			{
				state = OUT;
				// Typically a multiline comment is followed by a newline.
				// If this is the case, we want to eat the newline
				int escapec = getchar();
				if (escapec != '\n')
				{
					putchar(escapec);
				}
			}
			else if (state == OUT)
			{
				putchar(c);
				putchar(nextc);
			}
		}
		else if (c == '\n')
		{
			// Only print the newline if we aren't in a comment
			if (state == OUT)
			{
				putchar(c);
				tabs = 0;
			}
			// else state == IN, and a newline entered in a single line comment breaks the comment
			else if (secondchar == '/')
			{
				state = OUT;
				tabs = 0;
			}
		}
		else
		{
			// Only put chars if not in a comment
			if (state == OUT)
			{
				while (tabs > 0)
				{
					putchar('\t');
					--tabs;
				}
				putchar(c);
			}
		}
	}

	return 0;
}
