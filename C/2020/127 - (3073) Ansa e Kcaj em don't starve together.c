#include <stdio.h>

int batalha(int *vidaa, int vidam, int danoa, int danom)
{
    int testvida = *vidaa;

    while(1)
    {
        vidam -= danoa;
        
        if(vidam <= 0)
        {
            *vidaa = testvida;
            return 1;
        }

        testvida -= danom;
        
        if(testvida <= 0)
        {
            return 0;
        }
    }

}

struct usuario
{
    int vida, dano;
};

struct monstros
{
    int id, xp, dano, vida;

};

int main()
{
    int t, i, l, c, j;

//monstros
    scanf("%d", &t);

    struct monstros jogo[t];

    for(i = 0; i < t; i++)
    {
        scanf("%d%d%d%d", &jogo[i].id, &jogo[i].xp, &jogo[i].vida, &jogo[i].dano);
    }

    scanf("%d%d", &l, &c);

//mapa
    int mapa[l][c];

    for(i = 0; i < l; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &mapa[i][j]);
        }
    }

//ansa
    struct usuario ansa;
    int x, y;
    int qtmov;
    int win = 0;
    int xp = 0;

    scanf("%d%d", &ansa.vida, &ansa.dano);
    scanf("%d%d", &x, &y);
    scanf("%d", &qtmov);

    int mov[qtmov];

    for(i = 0; i < qtmov; i++)
    {
        scanf("%d", &mov[i]);
    }

//jogo


    for(i = 0; i < qtmov; i++)
    {
        if(mov[i] == 1)
        {
            if(x - 1 < 0)
            {
                x = l-1;
            }
            else
            {
                x -= 1;
            }
        }
        else if(mov[i] == 2)
        {
            if(y + 1 == c)
            {
                y = 0;
            }
            else
            {
                y += 1;
            }
        }
        else if(mov[i] == 3)
        {
            if(x + 1 == l)
            {
                x = 0;
            }
            else
            {
                x += 1;
            }
        }
        else if(mov[i] == 4)
        {
            if(y - 1 < 0)
            {
                y = c - 1;
            }
            else
            {
                y -= 1;
            }
        }
        
        if(mapa[x][y] != -1)
        {
            for(j = 0; j < t; j++)
            {
                if(jogo[j].id == mapa[x][y])
                {
                    if(batalha(&ansa.vida, jogo[j].vida, ansa.dano, jogo[j].dano) == 1 )
                    {
                        win++;
                        xp += jogo[j].xp;
                    }

                    break;
                }
            }
        }
    }

    printf("ansa derrotou: %d monstros\nansa conseguiu: %d de experiencia\nposicao final: (%d, %d)\n", win, xp, x, y);

    return 0;
}