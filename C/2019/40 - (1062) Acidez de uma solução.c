#include <stdio.h>

int main()
{
	float ph;

	scanf("%f", &ph);

	if(ph < 7)
	{
		printf("Acida\n");
	}

	else if (ph > 7)
	{
		printf("Basica\n");
	}

	else if (ph == 7)
	{
		printf("Neutra\n");
	}

	else 
	{
		printf("SEM CORRESPONDENCIA");
	}


	return 0;
}
