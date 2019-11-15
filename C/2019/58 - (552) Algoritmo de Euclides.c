#include <stdio.h>

int mdc_euclides(int a, int b)
{
	int resto = a % b;

	while (resto != 0)
	{
		a = b;
		b = resto;
		
		mdc_euclides(a, b);
		resto = a%b;
	}
	
	return b;

}

int main()
{
	int a, b, caso, resp, i;

	scanf("%d", &caso);

	for (i = 0; i < caso; i++)
	{
		scanf("%d%d", &a, &b);

		resp = mdc_euclides(a, b);

		printf("MDC(%d,%d) = %d\n", a, b, resp);

	}

	
	return 0;
}
