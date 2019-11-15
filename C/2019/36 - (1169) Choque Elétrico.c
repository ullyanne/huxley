#include <stdio.h>
#include <math.h>

int main()
{
	int p, lvl;

	scanf("%d", &lvl);

		if(lvl >= 1 && lvl <= 100)
		{
			if(lvl >= 1 && lvl <= 20)
			{
				p = 20 + pow(lvl, 3);
			}

			else if(lvl >= 21 && lvl <= 40)
			{
				p = 8000 + pow(lvl - 10, 2);
			}

			else if(lvl >= 41 && lvl <= 60)
			{
				p = 9000 + (5 * lvl);
			}

			else if(lvl >= 61 && lvl <= 80)
			{
				p = 9300 + (2 * lvl);
			}

			else if (lvl >= 81 && lvl <= 100)
			{
				p = 9500 + lvl;
			}

			printf("Potencia de : %d W\n", p);

		}

		else
		{
			printf("NAO CORRESPONDENTE\n");
		}

	return 0;
}
