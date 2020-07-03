#include <stdio.h>

int primo(int x)
{
    int i;

    if(x == 2)
    {
        return 1;
    }

    if(x <= 1)
    {
        return 0;
    }
    
    for(i = 2; i < x; i++)
    {
        if(x % i == 0)
        {
            return 0;
        }
    }

    return 1;
}


int main()
{
    int p, i, j, k;

    int winf = 0;
    int winf2 = 0;
    int qtwinf = 0;

    int wink = 0;
    int wink2 = 0;
    int qtwink = 0;

    scanf("%d", &p);

    int n;

    for(k = 0; k < p; k++)
    {
        scanf("%d", &n);

        int matriz[n][n];

        wink = 0;
        winf = 0;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &matriz[i][j]);

                if(i == j)
                {
                    if(primo(matriz[i][j]))
                    {
                        wink++;
                    }
                }
            }
        }

        for(i = 0, j = n-1; i < n, j >= 0; i++, j--)
        {
            if(primo(matriz[i][j]))
            {
                winf++;
            }
        }

        wink2 += wink;
        winf2 += winf;

        if(wink == winf)
        {
            printf("\nPartida %d:\nTio keke acumulou %d pontos\nTio fabio acumulou %d pontos\nHouve um empate\n", k+1, wink, winf);
        }
        else if(wink > winf)
        {
            qtwink++;

            printf("\nPartida %d:\nTio keke acumulou %d pontos\nTio fabio acumulou %d pontos\nVencedor da partida atual: Tio keke\n", k+1, wink, winf);
        }
        else
        {
           qtwinf++;

           printf("\nPartida %d:\nTio keke acumulou %d pontos\nTio fabio acumulou %d pontos\nVencedor da partida atual: Tio fabio\n", k+1, wink, winf);
        }

    }

    if(winf2 == wink2)
    {
        printf("\nResultado final do campeonato: Empate\n");
    }
    else if(winf2 > wink2)
    {
        printf("\nResultado final do campeonato: Tio fabio venceu o torneio com %d vitorias\n", qtwinf);
    }
    else
    {
        printf("\nResultado final do campeonato: Tio keke venceu o torneio com %d vitorias\n", qtwink);
    }




    return 0;
}