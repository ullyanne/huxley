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
	int a, b, resp;

	scanf("%d%d", &a, &b);

	resp = mdc_euclides(a, b);

		printf("%d\n", resp);

	
	return 0;
}
