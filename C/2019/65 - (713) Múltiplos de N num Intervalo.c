#include <stdio.h>

void multintervalo(int n, int i, int b)
{	
	int c = 0;

	for( ; i<=b; i++)
	{
		if(i%n == 0)
		{
			c = 1;
			printf("%d\n", i);
		}
	}

	if(c==0)
	{
		printf("INEXISTENTE\n");
	}

}


int main()
{
	int a, b, n;

	scanf("%d%d%d", &n, &a, &b);

	multintervalo(n, a, b);

	return 0;
}
