#include <stdio.h>

int main()
{
	int r, n, a2;
	int a1 = 1, total = a1;

	scanf("%d %d", &r, &n);


	while (a1 != n)
	{
		a2 = a1 +r;
		total = total + a2;
		a1 = a2;

		if (a2 > n)
		{	total = total - a2;
			break;
		}
	}

	printf("A somatoria da PA eh: %d\n", total);














	return 0;
}
