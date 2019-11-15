#include <stdio.h>

int main()
{
	float ph;

	printf("Digite o pH da solucao:\n");

	scanf("%f", &ph);

	if(ph >= 0 && ph < 7.0)
	{
		printf("Solucao acida\n");
	}

	else if (ph > 7.0 && ph <= 14.0)
	{
		printf("Solucao basica\n");
	}

	else if (ph == 7.0)
	{
		printf("Solucao neutra\n");
	}

	else 
	{
		printf("Valor do pH deve estar entre 0 e 14\n");
	}


	return 0;
}
