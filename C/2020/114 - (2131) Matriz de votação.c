#include <stdio.h>

int main()
{
    int P, E;
    int i, j;

    scanf("%d%d", &P, &E);

    int votoseleitores[E][P];
    int votosapurados[P];

    for(i = 0; i < P; i++) //preencher os votos com 0 para depois acumular valores
    {
        votosapurados[i] = 0;
    }

    for(i = 0; i < E; i++)
    {
        for(j = 0; j < P; j++)
        {
            scanf("%d", &votoseleitores[i][j]);
            
            votosapurados[j] += votoseleitores[i][j]; //votos apurados referente a cada princesa
        }
    }

    for(i = 0; i < P; i++)
    {
        printf("Princesa %d: %d voto(s)\n", i+1, votosapurados[i]);
    }


    return 0;
}
