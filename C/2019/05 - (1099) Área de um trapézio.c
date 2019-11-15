#include <stdio.h>

int main()
{
	int base_me, base_ma;
	float area, altura;

	scanf("%d%d%f", &base_me, &base_ma, &altura);

	area = ((base_ma + base_me) * altura )/2;

	printf("%.1f", area);



	return 0;
}
