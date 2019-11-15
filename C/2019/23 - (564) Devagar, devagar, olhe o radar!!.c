#include <stdio.h>

int main()
{
	float vvia, vcarro, x;

	scanf("%f%f", &vvia, &vcarro);

	x = (vcarro * 100)/vvia;

		if( 100 < x && x <= 120)
		{
			printf("85.13\n4\n");
		}
		else if (x > 120 && x <= 150)
		{
			printf("127.69\n5");
		}
		else if (x > 150)
		{
			printf("574.62\n7");
		}
		else
		{
			printf("0.00\n0");
		}


	return 0;
}
