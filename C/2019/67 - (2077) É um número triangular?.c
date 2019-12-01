#include <stdio.h>

int main()
{
	int n, i;
	int achei = 0;

	scanf("%d", &n);

	for(i=0; (i+2) <= (n/2); i++)
	{
		if((i * (i+1) * (i+2)) == n)
		{
			achei = 1;
			printf("%d * %d * %d = %d\nVerdadeiro\n", i, i+1, i+2, n);
		}
	}
	if (achei == 0)
	{
		printf("Falso\n");
	}
}
