#include <stdio.h>

int main()
{
	float qtp, qta, per;

	scanf("%f %f", &qtp, &qta);

	per = qta * 100/qtp;

	if (qta > qtp)
	{
		printf("Media invalida\n");
	}

	if (per >= 0 && per < 20)
	{
		printf("%.2f%% 4.40%% Pessimo\n", per);
	}

		else if (per >= 20 && per < 40)
	{
		printf("%.2f%% 31.65%% Ruim\n", per);

	}

			else if (per >= 40 && per < 60)
			{
				printf("%.2f%% 56.82%% Bom\n", per);

			}

				else if (per >= 60 && per < 80)
				{
					printf("%.2f%% 80.00%% Muito Bom\n", per);
				}

					else if (per >= 80 && per <= 100)
					{
						printf("%.2f%% 94.00%% Excelente\n", per);
					}

	return 0;
}
