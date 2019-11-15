#include <stdio.h>

int main()
{
	double x, y;

	scanf("%lf%lf", &x, &y);

	if(x > y)
	{
		printf("1\n");
	}

		else
		{
			printf("0\n");
		}

	if (x == y)
	{
		printf("1\n");
	}
		else 
		{
			printf("0\n");
		}

	if (x < y)
	{
		printf("1\n");
	}
		else
		{
			printf("0\n");
		}

	if (x != y)
	{
		printf("1\n");
	}
		else 
		{
			printf("0\n");
		}

	if (x >= y)
	{
		printf("1\n");
	}
		else
		{
			printf("0\n");
		}

	if (x <= y)
	{
		printf("1\n");
	}

		else 
		{
			printf("0\n");
		}


	return 0;
}
