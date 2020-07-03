#include <stdio.h>

struct carta
{
    int atk, life, jump;
};

void pulo(int jump, int n, int** win, int** posi, int** posj, struct carta usuario[][n])
{
    int i, j;

    jump++;

    for(i = **posi; i < n; i++)
    {
        for(j = **posj; j < n; j++)
        {
            jump--;

            if(i == n-1 && j == n-1)
            {
                **posi = i;
                **posj = j;
                **win = 1;

                i = n;
                break;
            }
            else if(jump == 0)
            {
                **posj = j;
                **posi = i;
                
                i = n;
                break;
            }
            
        }

        if(j == n)
        {
            **posj = 0;
        }
    }
}

int batalha
(int n, struct carta sofia[][n], struct carta ambr[][n], 
int* sposi, int* sposj, int* aposi, int* aposj, int* win)
{
    int sposi2 = *sposi, sposj2 = *sposj, aposi2 = *aposi, aposj2 = *aposj;

    int alife = ambr[aposi2][aposj2].life; 
    int slife = sofia[sposi2][sposj2].life;

    int adano = ambr[aposi2][aposj2].atk;
    int sdano = sofia[sposi2][sposj2].atk;
    
    while(1)
    {
        alife -= sdano;

        if(alife <= 0)
        {
            pulo(sofia[sposi2][sposj2].jump, n, &win, &sposi, &sposj, sofia);
            return 1;
        }

        slife -= adano;

        if(slife <= 0)
        {
            pulo(ambr[aposi2][aposj2].jump, n, &win, &aposi, &aposj, ambr);
            return 0;
        }
    }
}


void ler(int n, struct carta usuario[][n])
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d%d%d", &usuario[i][j].atk, &usuario[i][j].life, &usuario[i][j].jump);
        }
    }
}


int main()
{
    int n, r, i, j, k;
    int win = 0;

    scanf("%d", &n);

    struct carta sofia[n][n];
    struct carta ambr[n][n];

    ler(n, sofia);
    ler(n, ambr);

    scanf("%d", &r);

    int sposi = 0, sposj = 0, aposi = 0, aposj = 0;

    for(k = 0; k < r && win != 1; k++)
    {
        if(batalha(n, sofia, ambr, &sposi, &sposj, &aposi, &aposj, &win) )
        {
            if(win)
            {
                printf("Sofia: (%d, %d)\nAmbrosio: (%d, %d)\nSofia venceu\n", sposi, sposj, aposi, aposj);
            }  
        }
        else
        {
            if(win)
            {
                printf("Sofia: (%d, %d)\nAmbrosio: (%d, %d)\nAmbrosio venceu\n", sposi, sposj, aposi, aposj);
            }
        }
        
    }

    if(win == 0)
    {
        printf("Sofia: (%d, %d)\nAmbrosio: (%d, %d)\nNinguem venceu\n", sposi, sposj, aposi, aposj);
    }

    return 0;
}