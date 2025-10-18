#include <stdio.h>
#define MAXLENGTH 1000
#define OUT 0
#define IN 1

int get_line(char s[], int limit);

int main()
{
	int len;
	char line[MAXLENGTH];

	len = 0;

	while ((len = get_line(line, MAXLENGTH)) > 0)
		printf("(%d): %s", len, line);

	return 0;
}

int get_line(char s[], int limit)
{
	int c, i, lchar;

	lchar = 0;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (!(c ==  ' ' || c == '\t'))
		{
			lchar = i;
		} 
		
		if (i < MAXLENGTH)
			s[i] = c;
	}
	
	/* 
	 * If line wasn't empty, need to increment last char by 1,
	 * otherwise if the for loop was broken due to a newline char
	 * the subsequent code to append the newline to the end of the char
	 * array will overwrite the last char instead
	 */
	if (lchar) ++lchar;

	if (c == '\n' && lchar != 0)
	{
		s[lchar] = '\n';
		++lchar;
	}

	s[lchar] = '\0';

	return lchar;
}
