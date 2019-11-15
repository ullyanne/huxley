#include <stdio.h>
#include <math.h>

int main()
{
	double raiocm, raiom, pi, area;

	scanf("%lf", &raiocm);

	raiom = raiocm/100;

	pi = 3.14159;

	area = pi * pow(raiom,2);

	printf("Area = %.4lf\n", area);

	return 0;
}
