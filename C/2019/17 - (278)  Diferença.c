#include <stdio.h>

int main()
{
	int a, b, c, d, produtoab, produtocd, diferenca;

	scanf("%d%d%d%d", &a, &b, &c, &d);

	produtoab = a * b;
	produtocd = c * d;

	diferenca = (produtoab - produtocd);

	printf("DIFERENCA = %d", diferenca);

	return 0;
}
