#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, i, j, qtcomandos;
    int posicao[2]; //[0] -> x (linha), [1] -> y (coluna)

    scanf("%d%d", &n, &m);



    int A[n][m];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &A[i][j]);

        }

    }

    scanf("%d", &qtcomandos);
    // scanf("%*[^\n]");
    // scanf("%*c");


    char sequencia[qtcomandos];

    for(i = 0; i < qtcomandos; i++)
    {
        scanf(" %c", &sequencia[i]);
    }



    scanf("%d%d", &posicao[0], &posicao[1]);



    for(j = 0; j < qtcomandos; j++)
    {
        if(sequencia[j] == 'C')
        {
            if(A [posicao[0] - 1][ posicao[1] ] != 0 && posicao[0] != 0)
            {
                posicao[0] = posicao[0] - 1;
            }
        }
        else if(sequencia[j] == 'D')
        {
            if(A [ posicao[0] ][ posicao[1] + 1 ] != 0 && posicao[1] != (m-1) )
            {
                posicao[1] = posicao[1] + 1;
            }
        }
        else if(sequencia[j] == 'B')
        {
            if(A [ posicao[0] +1 ][ posicao[1] ] != 0 && posicao[0] != (n-1) )
            {
                posicao[0] = posicao[0] + 1;
            }
        }
        else if(sequencia[j] == 'E')
        {
            if(A [ posicao[0] ][ posicao[1] - 1 ] != 0 && posicao[1] != 0 )
            {
                posicao[1] = posicao[1] - 1;
            }
        }
    }

    printf("(%d,%d)", posicao[0], posicao[1] );




    return 0;
}
