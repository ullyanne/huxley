#include <stdio.h>

int main()
{
	int num1, num2;
	float num3, media;

	scanf("%d%d%f", &num1, &num2, &num3);

	if (num1 < 0 || num1 > 100 || num2 < 0 || num2 > 100 || num3 < 0 || num3 > 100)
	{
		printf("Media invalida");
	}	

	media = (num1 + num2 + num3)/3;

	if( 0 <= media && media <= 40.0)
	{
		printf("A media do aluno foi %.2f e ele foi REPROVADO", media);
	}

	else if(40.0 < media && media < 70.0)
	{
		printf("A media do aluno foi %.2f e ele foi FINAL", media);
	}

	else if (70.0 <= media && media <= 100.0)
	{
		printf("A media do aluno foi %.2f e ele foi APROVADO", media);
	}

	return 0;
}
