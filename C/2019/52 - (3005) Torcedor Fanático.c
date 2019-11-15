#include <stdio.h>

int main()
{
	int C, T, A, L, E;

	scanf("%d%d%d%d%d", &C, &T, &A, &L, &E);

	double chance = 100.0;

	if (C == 1)
	{
		if (T == 1)
		{
			chance = chance + 33.21;
		}

		else if (T == 2)
		{
			chance = chance + 10.51;
		}

		else if (T == 3)
		{
			chance = chance - 20.7;
		}

			if (A > 40000)
			{
				chance = (A * 0.0008) + chance;
			}
			else 
			{
				chance = chance - (A * 0.0008);
			}

				if (E > 0)
				{
					chance = (E * 2.7) + chance;
				}
				else
				{
					chance = chance - (E * 1.8); 
				}

	}



	if (C == 0)
	{
		if (T == 1)
		{
			chance = chance - 10.87;
		}

		//else if (T == 2 || T == 3)
		//{
		//	chance = 0;
		//}//

			if (A > 45000)
			{
				chance = chance - (A * 0.0003);
			}
			else 
			{
				chance = chance - (A * 0.0001);
			}

				if (E > 0)
				{
					chance = (E * 5.2) + chance;
				}
				else
				{
					chance = chance - (E * 1.5); 
				}
	}

	chance = chance - (2.7 * L);

	if (C == 0)
	{
		if (T == 2 || T == 3)
		{
			chance = 0;
		}
	}

	if (chance < 0)
	{
		chance = 0;
	}

	if (chance > 100)
	{
		chance = 100;
	}

	printf("A chance de vitoria do flamengo e de %.2lf\n", chance);


	return 0;
}
