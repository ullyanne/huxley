#include <stdio.h>

int main()
{
	int minutos, expediente, total;

	scanf("%d", &minutos);

	expediente = 8 * 60;
	total = expediente/minutos;

	printf("%d\n", total);

	return 0;
}
