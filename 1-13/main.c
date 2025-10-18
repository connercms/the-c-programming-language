#include <stdio.h>

#define OUT 0
#define IN 1
#define MAXLENGTH 255
int main()
{
	int c, state, len, maxlen;
	state=OUT;
	maxlen = len = 0;
	int wordlen[MAXLENGTH];
	
	/* Initialize items in the array to 0 */
	for (int i = 0; i < MAXLENGTH; ++i)
		wordlen[i]=0;

	while ((c=getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == IN) 
			{
				++wordlen[len]; // if breaking out of word, record length
				if (len > maxlen) maxlen = len;
			}
			state = OUT;
			len=0; 
		}
		else
		{
			state = IN; // otherwise we must be inside a word
			++len; 
		}
	}


	for (int i = 0; i <= maxlen; ++i) 
		printf("%d: %d\n", i, wordlen[i]);

	
	for (int i = maxlen; i > 0; --i)
	{
		for (int x = 0; x <= maxlen; ++x)
		{
			if (wordlen[x] >= i) 
				printf(" [] ");
			else 
				printf("%4s", " ");
			
		}
		putchar('\n');
	}
	
	for (int x = 0; x <= maxlen; ++x)
		printf(" %2d ", x);

	putchar('\n');
	
	return 0;
}
