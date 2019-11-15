#include <stdio.h>

int main()
{
	int number, horas;
	float nph, salario;

	scanf("%d%d%f", &number, &horas, &nph);

	salario = nph * horas;

	printf("NUMBER = %d\nSALARY = R$ %.2f", number, salario);


	return 0;
}
