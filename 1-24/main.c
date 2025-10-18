/*
 * A program to check a C program
 * for rudimentary syntax errors like
 * unbalanced parentheses, brackets and braces.
 * Don't forget about quotes, both single and double,
 * escape sequences, and comments.
 *
 * I'm going to have to check that parenthesis,
 * brackets, braces, single and double quotes,
 * escape sequences and comments are
 * all terminated correctly.
 */

#include <stdio.h>

#define OUT 0
#define IN_CHAR 1
#define IN_STRING 2
#define IN_COMMENT 3

int main()
{
	int c, parens, brackets, braces, squotes, dquotes, lchar, state;
	parens = brackets = braces = squotes = dquotes = 0;
	state = OUT;

	while ((c = getchar()) != EOF)
	{
		if (state == IN_COMMENT && c == '*' && lchar == '*')
		{
			int nchar = getchar();
			if (nchar == '/')
			{
				state = OUT;
			}
		}
		else if (c == '\n')
		{
			if (IN_COMMENT && lchar == '/')
				state = OUT;
		}
		else if (c == '/')
		{
			int nchar = getchar();
			if (nchar == '/' || nchar == '*')
			{
				lchar = nchar;
				state = IN_COMMENT;
			}
		}
		else if (c == '\\')
		{
			int nchar = getchar();
			if ((state == IN_CHAR && nchar == '\'') || (state == IN_STRING && nchar == '\"'))
			{
				// do nothing?
			}
		}
		else if (c == '(')
		{
			++parens;
		}
		else if (c == ')')
		{
			--parens;
		}
		else if (c == '[')
		{
			++brackets;
		}
		else if (c == ']')
		{
			--brackets;
		}
		else if (c == '{')
		{
			++braces;
		}
		else if (c == '}')
		{
			--braces;
		}
		else if (c == '\'')
		{
			if (state == OUT)
			{
				state = IN_CHAR;
				++squotes;
			}
			else
			{
				state = OUT;
				--squotes;
			}
		}
		else if (c == '\"')
		{
			if (state == OUT)
			{
				state = IN_STRING;
				++dquotes;
			}
			else
			{
				state = OUT;
				--dquotes;
			}
		}
	}

	printf(
		"Parenthesis: %d, brackets: %d, braces: %d, single quotes: %d, double quotes: %d\n",
		parens,
		brackets,
		braces,
		squotes,
		dquotes);

	return 0;
}
