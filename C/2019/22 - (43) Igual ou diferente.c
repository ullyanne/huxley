#include <stdio.h>

int main()
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	if (a == b)
	{
		if (b  == c)
		{
			printf("1");
		}

		else
		{
			printf("3");
		}
	}

	else if (b == c)
	{
		printf("3");
	}

	else 
	{
		printf("2");
	}




	return 0;
}
