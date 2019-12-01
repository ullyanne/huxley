#include <stdio.h>


void divisores(int x)
{	int c = 0;
	int i;

	for(i = 1; i <= x; i++)
	{
		if(x%i==0)
		{	
			if (i%3 == 0)
			{
				c++;
			}
		}
	}

	if(c == 0)
	{
		printf("O numero nao possui divisores multiplos de 3!\n");
	}
	else
	{
		printf("%d\n", c);
	}
}

int main()
{
	int n;

	scanf("%d", &n);

	divisores(n);

	return 0;
}
