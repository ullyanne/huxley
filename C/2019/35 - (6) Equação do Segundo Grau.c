#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, delta, x, x1, x2;

	scanf("%lf%lf%lf", &a, &b, &c);

	delta = pow(b, 2) + (- 4 * a * c);

	x1 = ( -b + ( sqrt(delta) ) )/(2 * a);
	x2 = ( -b - ( sqrt(delta) ) )/(2 * a);

		if (a == 0)
		{
			printf("NEESG\n");
		}

		else
		{
			if (delta < 0)
			{
				printf("NRR\n");
			}

				else if (delta == 0 || delta > 0)
				{	
					printf("%.2f\n%.2f\n", x1, x2);

				}

		}



	return 0;
}
