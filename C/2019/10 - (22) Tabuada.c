#include <stdio.h>

int main()
{
	int n, i, p;

	i = 1;

	scanf("%d", &n);

	while(i <= 9)
	{
		p = (n * i);

		printf("%d X %d = %d\n", n, i, p);

		i++;
	}




}
