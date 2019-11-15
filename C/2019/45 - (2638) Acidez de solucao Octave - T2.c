#include <stdio.h>

int main()
{
	int ph;

	scanf("%d", &ph);

	printf("Digite o pH da solucao:\n");

	if (ph < 7 && ph >= 0)
	{
		printf("Essa solucao e acida.\n");
	}

	else if (ph > 7 && ph <= 14)
	{
		printf("Essa solucao e basica.\n");
	}

	else if (ph == 7)
	{
		printf("Essa solucao e neutra.\n");
	}

	else
	{
		printf("Valor deve estar entre 0 e 14.\n");
	}




	return 0;
}
