#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, p, a1, a2;



	for ( ; ; )
	{
		scanf("%d", &n);
			
		if (n == 0)
		{
			break;
		}

		if (n % 2 == 0)
		{
			printf("SEM RESPOSTA\n");
			return 0;
		}

		for (i = 0;  ; i++)
		{

			a1 = (i * i);
			a2 = ((1 + i) * (1 + i));
			p = abs(a1 - a2);

			if (p == n)
			{
				printf("%d - %d\n", a2, a1);
				break;
			}
		}

	}


	return 0;
}
