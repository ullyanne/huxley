#include <stdio.h>

int primoounao(int x)
{	
	int i;

	if (x <= 1)
	{
		return 0;
	}

	else
	{
		for( i = 2; i < x; i++)
		{
			if (x % i == 0)
			{
				return 0;
			}
		}

	}

	return 1;

}

int main()
{
	int n, p;

	scanf("%d", &n);

	while (n != -1)
	{
		p = primoounao(n);

		printf("%d\n", p);

		scanf("%d", &n);

	}

	return 0;
}
