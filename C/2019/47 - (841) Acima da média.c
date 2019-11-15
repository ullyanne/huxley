#include <stdio.h>

int main()
{
	int contador, i;
	float media;
	float a[3];

	contador = 0;

	for (i = 0; i <= 2; i++)
	{
		scanf("%f", &a[i]);
	}

	media = (a[0] + a[1] + a[2])/ 3;

	for (i=0 ; i <= 2; i++)
	{
		if (a[i] > media)
		{
			contador++;
		}
	}

	printf("%d\n", contador);


}
