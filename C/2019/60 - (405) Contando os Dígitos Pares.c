#include <stdio.h>

int cont = 0;

int contapar(int x)
{	int quoc = x/10;
	int resto = x%10;

	if (quoc == 0)
	{
		if (resto % 2 == 0)
		{
			cont++;
		}

		return cont;
	}
	else 
	{
		if (resto % 2 == 0)
		{
			cont++;
		}

		x = (x - resto) * 0.1;	

		contapar(x);
	}

}

int main()
{
	int numero, resp;

	scanf("%d", &numero);

	resp = contapar(numero);

	printf("%d\n", resp);

	return 0;
}
