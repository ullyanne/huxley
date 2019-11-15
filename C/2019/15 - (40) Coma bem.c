#include <stdio.h>

int main()
{
	float gasto, garc, pago;

	scanf("%f", &gasto);

	garc = 0.1 * gasto;
	pago = garc + gasto;

	printf("%.2f", pago);



	return 0;
}
