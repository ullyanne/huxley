#include <stdio.h>
#include <math.h>

int potencia(int x)
{
	int i, pot;

	for(i=0; ; i++)
	{
		pot = pow(2, i);

		if(pot == x)
		{
			return 1;
		}
		if(pot > x)
		{
			return 0;
		}

	}
}

int primo(int x)
{
	int i;

	if(x == 1 || x <= 0)
	{
		return 0;
	}

	for(i = 3; i < x; i++)
	{
		if(x%i == 0)
		{
			return 0;

		}
	}

	return 1;

}


int main()
{
	int p, n, k, dadof, dadoa, casaf, casaa, i, j, passagemf, passagema;

	casaf = 0;
	casaa= 0;
	passagemf = 0;
	passagema = 0;

	scanf("%d%d", &p, &n);

	for(i = 1 ; i<= p ; i++)
	{
		scanf("%d", &k);

		for(j = 1; j<= k; j++)
		{
			scanf("%d%d", &dadof, &dadoa);

		
			casaf += dadof; //f


			if(casaf > n)
			{
				passagemf += 1;

				casaf = 0;
			}
			else if( potencia(casaf) == 1)
			{
				casaf += 2;

				if(casaf > n)
				{
					passagemf += 1;
					casaf = 0;
				}

			}
			else if( primo(casaf) == 1)
			{
				casaf -= 2;
			}

			

			casaa += dadoa; //a


			if( casaa > n)
			{
				passagema += 1;
				casaa = 0;
			}
			else if( potencia(casaa) == 1)
			{
				casaa += 2;

				if(casaa > n)
				{
					passagema += 1;
					casaa = 0;
				}
			}
			else if( primo(casaa) == 1)
			{
				casaa -= 2;

			}

		} //final do forj


		if(passagemf > passagema)
		{
			printf("Partida %d : Fabio venceu na posicao %d passando %d vezes pelo final do tabuleiro\n", i, casaf, passagemf);
		}
		else if (passagema > passagemf)
		{
			printf("Partida %d : Ayalla venceu na posicao %d passando %d vezes pelo final do tabuleiro\n", i, casaa, passagema);
		}
		else //empate
		{
			if(casaf > casaa)
			{
				printf("Partida %d : Fabio venceu na posicao %d passando %d vezes pelo final do tabuleiro\n", i, casaf, passagemf);
			}
			else if (casaa > casaf)
			{
				printf("Partida %d : Ayalla venceu na posicao %d passando %d vezes pelo final do tabuleiro\n", i, casaa, passagema);
			}
			else
			{
				printf("Partida %d : Houve um empate nas posicoes %d e %d\n", i, casaf, casaa);
			}
		}

		casaf = 0;
		casaa= 0;
		passagema = 0;
		passagemf = 0;

	}

	return 0;
}
