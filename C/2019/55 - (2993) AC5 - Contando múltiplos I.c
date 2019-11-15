#include <stdio.h>

int main()
{
	int x, n, cont, i, p;

	scanf("%d %d", &x, &n);

	cont = 0;
	i = 1;
	p = 0;

	if (x >= n)
	{
		printf("O numero %d tem %d multiplos menores que %d.\n", x, cont, n);
	}

		while (p < n)
		{
			p = x * i;
			cont++;
			i++;
			p = x * i;
		}

		printf("O numero %d tem %d multiplos menores que %d.\n", x, cont, n);


	return 0;
}
