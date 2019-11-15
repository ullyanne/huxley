#include <stdio.h>

int main()
{
	double a, b, c;

	scanf("%lf%lf%lf", &a, &b, &c);

		if(a != b || b != c)
		{
			if (a == c || a == b || b == c)
			{
				printf("isosceles\n");
			}

			else 
			{
				printf("escaleno\n");
			}
		}

		else
		{
			printf("equilatero\n");
		}






	return 0;
}
