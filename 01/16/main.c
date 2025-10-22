#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy_line(char to[], char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy_line(longest, line);
		}
	}

	if (max > 0)
	{
		printf("(%d): %s\n", max, longest);
	}

	return 0;
}

int get_line(char s[], int limit)
{
	int c, i;

	/*
	 * While line does not exceed the MAXLINE,
	 * and while not EOF,
	 * and while not a new line (\n),
	 * add the char c to array s
	 */
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i < limit - 1)
			s[i] = c;	
	}

	/*
	 * If for loop broke because c == '\n', 
	 * append the new line char to array 
	 * and increment the length counter 'i'
	 */
	if (c == '\n') 
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0'; // Write the null terminator to the char array

	return i; // return the length
}

void copy_line(char to[], char from[])
{
	int i;

	i = 0;
	/*  This is similar to doing (c = getchar()) != EOF */
	while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}
