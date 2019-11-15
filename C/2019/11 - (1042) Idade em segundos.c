#include <stdio.h>

int main()
{
	int idade, conta;

	scanf("%d", &idade);

	conta = (60 * 60 * 24 * 365) * idade;

	printf("%d", conta);

	return 0;
}
