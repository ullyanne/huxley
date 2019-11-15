#include <stdio.h>

int main()
{
	double diaria_carro, diaria_km, desconto, dias, km, total;

	scanf("%lf%lf", &dias, &km);

	diaria_carro = dias * 30;
	diaria_km = km * 0.01;

	total = (diaria_carro + diaria_km) - (0.1 * (diaria_carro + diaria_km));

	printf("%.2lf", total);

	return 0;
}
