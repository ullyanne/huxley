#include <stdio.h>

int main()
{
    int l, c, i, j;

    scanf("%d%d", &l, &c);

    int A[l][c];
    int tA[c][l];

    for(i = 0; i < l; i++) //linhas
    {
        for(j = 0; j < c; j++) //colunas
        {
            scanf("%d", &A[i][j]);
            tA[j][i] = A[i][j];
        }
    }

    for(i = 0; i < c; i++) //linhas
    {
        printf("| ");

        for(j = 0; j < l; j++) //colunas
        {
            printf("%d ", tA[i][j]);
        }
        printf("|\n");
    }  



    return 0;
}
