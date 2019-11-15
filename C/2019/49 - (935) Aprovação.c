#include <stdio.h>

int main()
{
	float a, b, c, media;

	scanf("%f%f%f", &a, &b, &c);

	media = (a+b+c)/3;

	if (media >= 7)
	{
		printf("Informe a primeira nota:\nInforme a segunda nota:\nInforme a terceira nota:\nAprovado com media %.1f\n", media);
	}

	else if (media >= 5)
	{
		printf("Informe a primeira nota:\nInforme a segunda nota:\nInforme a terceira nota:\nRecuperacao com media %.1f\n", media);
	}

	else if (media < 5)
	{
		printf("Informe a primeira nota:\nInforme a segunda nota:\nInforme a terceira nota:\nReprovado com media %.1f\n", media);
	}



	return 0;
}
