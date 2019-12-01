#include <stdio.h>

int primosi(int x, int y)
{
	int aux;
	int i;

	if(x < y)
	{
		aux = y;
		y = x;
		x = aux;
	}

	for(i = 2; i <= y ; i++)
	{
		if(x%i == 0 && y%i == 0)
		{
			return 0;
		}
	}

	return 1; 
}

int primo(int x)
{
	int i;

	if(x == 1 || x <= 0)
	{
		return 0;
	}

	for(i = 2; i < x; i++)
	{
		if(x%i == 0)
		{
			return 0;

		}
	}

	return 1;

}


int main()
{
	int t, n, m, atual, i;

	scanf("%d%d%d", &t, &n, &m);

	printf("%d %d ", n, m);

	for(i = 3; i <= t; i++)
	{
		if( primo(m) == 1 )
		{
			atual = (2 * m);
		}
		else if( primosi(n, m) == 1)
		{
			atual = (2 * (n + m)) - 3;
		}
		else
		{
			atual = (m + 1);
		}

		printf("%d ", atual);

		n = m;
		m = atual;
	}

	return 0;
}
