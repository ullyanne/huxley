#include <stdio.h>

int main()
{
	float a, b, aux;

	scanf("%f%f", &a, &b);

	if (a < b)
	{
		aux = b;
		b = a;
		a = aux;
	}

	printf("Digite um numero:\nDigite outro numero:\nMaior numero: %.1f\n", a);


	return 0;
}
