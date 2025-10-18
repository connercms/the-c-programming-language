/*
 * A program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column
 * of input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>
#define LINE_LENGTH 20
#define TABSTOP 8

int main()
{
	int c, pos;
	char line[LINE_LENGTH];
	pos = 0;

	while ((c = getchar()) != EOF)
	{
		// If it was a newline, print the line and reset the pos
		if (c == '\n')
		{
			line[pos] = c;
			++pos;
			line[pos] = '\0';
			printf("%s", line);
			pos = 0;
		}

		else
		{
			// If char was a tab, replace with enough spaces to get to next
			// column and increment the counter accordingly
			if (c == '\t')
			{
				do
				{
					line[pos] = ' ';
					++pos;
				} while (pos % TABSTOP != 0);
			}
			else
			{
				line[pos] = c;
				++pos;
			}
			// Otherwise, add the char to the line buffer and increment the pos
			// If the pos is now at the break point
			if (pos >= LINE_LENGTH)
			{
				int j, lblank;
				// Find the last blank leading up to the break point
				for (j = lblank = LINE_LENGTH; j > 0; --j)
				{
					if (line[j] == ' ')
					{
						lblank = j;
						break;
					}
				}
				// Then print up to that blank
				for (int i = 0; i < lblank; ++i)
				{
					putchar(line[i]);
				}

				putchar('\n');
				// Now move anything after the last blank to the front of the array and continue
				int i = 0;

				for (lblank; lblank < LINE_LENGTH; ++lblank)
				{
					// Go to the first non blank
					while (line[lblank] == ' ')
						++lblank;

					line[i] = line[lblank];
					++i;
				}
				pos = i;
			}
		}
	}
}
