#include <stdio.h>

int main()
{
	float sal, nsal;

	scanf("%f", &sal);

	if (sal <= 280)
	{
		nsal = (0.2 * sal) + sal;
	}

	else if (sal > 280 && sal <= 700)
	{
		nsal = (0.15 * sal) + sal;
	}

	else if (sal > 700 && sal < 1500)
	{
		nsal = (0.1 * sal) + sal;
	}

	else if (sal >= 1500)
	{
		nsal = (0.5 * sal) + sal;
	}

	printf("%.2f\n", nsal);


	return 0;
}
