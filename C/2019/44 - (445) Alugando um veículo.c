#include <stdio.h>

int main()
{
	int dias, kmg, km;
	float diaria, taxa, total;

	scanf("%d %d", &dias, &km);

	kmg = dias * 100;
	diaria = 90 * dias;

	if (km > kmg)
	{
		taxa = 12 * (km - kmg);
	}

	else
	{
		taxa = 0;
	}

	total = taxa + diaria;

	printf("%.2f\n", total);

	return 0;
}
