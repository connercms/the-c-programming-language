#include <stdio.h>

#define STEP 20

float convert(int fahr);

int main()
{
	float celsius;

	printf("%3s%6s\n", "F", "C");
	for (int fahr = 0; fahr <= 300; fahr +=  STEP)
	{
		printf("%3d%6.1f\n", fahr, convert(fahr));
	}
}

float convert(int fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}
