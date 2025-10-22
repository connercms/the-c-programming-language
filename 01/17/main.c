#include <stdio.h>
#define MAXLENGTH 1000

int get_line(char s[], int limit);

int main()
{
	int len;
	char line[MAXLENGTH];

	len = 0;

	while ((len = get_line(line, MAXLENGTH)) > 0)
		if (len > 80)
			printf("%s", line);

	return 0;
}

int get_line(char s[], int limit)
{
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i < MAXLENGTH)
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
