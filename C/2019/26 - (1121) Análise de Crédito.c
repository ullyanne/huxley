#include <stdio.h>

int main()
{
	double sal, c, n, x, lim;

	scanf("%lf%lf", &sal, &c);

	n = (c/sal);

	if(n < 0.3)
	{
		x = 0.3 - n;

		lim = x * sal;

		printf("%.2lf\n", lim);

	}

	else
	{
		printf("0.00\n");

	}






	return 0;
}
