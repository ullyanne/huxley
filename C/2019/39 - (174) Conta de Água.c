#include <stdio.h>

int main()
{
	int consumo, conta;

		scanf("%d", &consumo);

	int dif[4] = {7 , consumo-10, consumo-30, consumo-100};

	if (consumo >= 0 && consumo <= 10)
	{
		conta = dif[0];
	}

	else if(consumo >= 11 && consumo <= 30)
	{
		conta = dif[1] + dif[0];
	}

	else if(consumo >= 31 && consumo <= 100)
	{
		conta = (dif[2] * 2) + dif[0] + 20;
	}

	else if(consumo >= 101)
	{
		conta = (dif[3] * 5) + dif[0] + 160;
	}

	printf("%d\n", conta);


	return 0;
}
