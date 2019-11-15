#include <stdio.h>

int main()
{
	float sal, nsal;

	scanf("%f", &sal);

	if(sal > 500)
	{
		nsal = 0.1 * sal + sal;

		printf("%.2f", nsal);
	}

	else if(sal > 300 & sal <= 500)
	{
		nsal = 0.07 * sal + sal;

		printf("%.2f", nsal);
	}

	else 
	{
		nsal = 0.05 * sal + sal;

		printf("%.2f", nsal);
	}



	return 0;
}
