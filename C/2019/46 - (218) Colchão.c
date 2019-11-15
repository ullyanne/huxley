#include <stdio.h>

int main()
{
	int a, b, c, aux, h, l;

	scanf("%d %d %d", &a, &b, &c);

	scanf("%d %d", &h, &l);

	if (a <= b)
	{
		aux = b;
		b = a;
		a = aux;
	}

	if (a <= c)
	{
		aux = c;
		c = a;
		a = aux;
	}

	if (b <= h && c <= l || c <= h && b <= l)
	{
		printf ("S\n");
	}

	else 
	{
		printf("N\n");
	}


	return 0;
}
