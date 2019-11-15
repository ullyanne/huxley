#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c, d, e, f, g, h;

	scanf("%d%d%d", &a, &b, &c);

	d = abs((a - b + c));
	e = abs((a + b - c));
	f = (a - b);
	g = (a - c);
	h = (b - c);

	if(d == 0 || e == 0 || f == 0 || g == 0 || h == 0 )
	{
		printf("S\n");
	}

	else 
	{
		printf("N\n");
	}






	return 0;
}
