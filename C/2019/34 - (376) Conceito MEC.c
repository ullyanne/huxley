#include <stdio.h>

int main()
{
	double qtl, qta, x;

	scanf("%lf%lf", &qtl, &qta);

	x = qta/qtl;

	if (x <= 8)
	{
		printf("A\n");
	}

	else if (x >= 9 && x <= 12)
	{
		printf("B\n");
	}

	else if (x >= 13 && x <= 18)
	{
		printf("C\n");
	}

	else if (x > 18)
	{
		printf("D\n");
	}


	return 0;
}
