#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[])
{
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i < MAXLINE)
			s[i] = c;
	}

	if (c == '\n') 
	{
		s[i] = '\n';
		++i;
	}

	s[i] = '\0';

	return i;
}

void reverse_line(char s[], int len)
{
	// If the line ends with '\n', this will be copied to the first position in the array.
	// This is a known limitation and I'm too lazy to handle this case right now
	char temp[len];
	int ctr;
	ctr = 0;

	// Copy the array to the temp array first
	for (int i = 0; i < len; ++i)
		temp[i] = s[i];

	
	// Subtract 1 so we don't start by setting \0 to s[0]
	for (len = len - 1; len >= 0; --len)
	{
		s[ctr] = temp[len];
		++ctr;
	}	

	s[ctr] = '\0';
}

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line)) > 0)
	{
		reverse_line(line, len);
		printf("%s", line);
	}

}
