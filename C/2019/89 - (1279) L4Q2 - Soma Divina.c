#include <stdio.h>

int main()
{
    int sinalizador = 0; //se for 1, a matriz não é vazia. vazia até que me provem o contrário
    int N, i, j;
    char resposta[]= "Vazia";

    scanf("%d", &N);

    int A[N][N];
    int B[N][N];
    int R[N][N];

    for(i = 0; i < N; i++) //linhas
    {
        for(j = 0; j < N; j++) //colunas
        {
            scanf("%d", &A[i][j]);
        }
    }

    for(i = 0; i < N; i++) //linhas
    {
        for(j = 0; j < N; j++) //colunas
        {
            scanf("%d", &B[i][j]);
            R[i][j] = B[i][j] + A[i][j];

            if(R[i][j] != 0)
            {
                sinalizador = 1;
            }
        }
    }

    if(!sinalizador)
    {
        puts(resposta);
        return 0;
    }

    for(i = 0; i < N; i++) //linhas
    {
        for(j = 0; j < N; j++) //colunas
        {
            printf("%d\n", R[i][j]);
        }
    }


    return 0;
}
