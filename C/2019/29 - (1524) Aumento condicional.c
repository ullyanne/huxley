#include <stdio.h>

int main()
{
	float sal, au, nsal;
	int per;

	scanf("%f", &sal);

	if(sal <= 280)
	{
		per = 20;
		au = per * 0.01 * sal;
		nsal = sal + au;

		printf("%.2f\n%d\n%.2f\n%.2f\n", sal, per, au, nsal);
	}

		else if(sal > 280 && sal <= 700)
		{
			per = 15;
			au = per * 0.01 * sal;
			nsal = sal + au;

			printf("%.2f\n%d\n%.2f\n%.2f\n", sal, per, au, nsal);
		}

			else if(sal > 700 && sal < 1500)
			{
				per = 10;
				au = per * 0.01 * sal;
				nsal = sal + au;

				printf("%.2f\n%d\n%.2f\n%.2f\n", sal, per, au, nsal);
			}

				else if (sal >= 1500)
				{
					per = 5;
					au = per * 0.01 * sal;
					nsal = sal + au;

					printf("%.2f\n%d\n%.2f\n%.2f\n", sal, per, au, nsal);
				}

	return 0;
}
