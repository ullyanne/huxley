#include <stdio.h>

int fatorial(int x)
{
	int r;

	if (x == 0)
	{
		r = 1;
	}
	else
	{
		r = x * fatorial(x - 1);
	}

	return r;
}

int main()
{
	int numero, resp;

	scanf("%d", &numero);

	while (numero != -1)
	{
		resp = fatorial(numero);

		printf("%d\n", resp);

		scanf("%d", &numero);

	}
	

	return 0;

}
