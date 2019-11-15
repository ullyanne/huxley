#include <stdio.h>

int main()
{
	float cod[4] = {5.3, 6, 3.2, 2.5};
	float qtc, desc;
	int qtp, j;


	scanf("%d%d", &j, &qtp);

	
	qtc = cod[j-1] * qtp;

	if(qtc >= 40 || qtp >= 15)
	{
		desc = qtc - (0.15 * qtc);
		printf("R$ %.2f\n", desc);
	}

	else
	{
		printf("R$ %.2f\n", qtc);
	}
	

	return 0;
}
