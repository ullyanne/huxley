#include <stdio.h>
#include <stdlib.h>


int main()
{
    int l, c, i, j, k, qtdestruicao, eliminacoesrestantes, ndestruidas;
    int celulasvivas = 0;
    int destruidas = 0;
    int space = 0; //espaço pra printar
    
    scanf("%d%d", &l, &c);

    int A[l][c]; //array do usuário

    for(i = 0; i < l; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
            if(A[i][j] == 1)
            {
                celulasvivas++;
            }
        }
    }

    scanf("%d", &qtdestruicao);

    if(l%2 == 0) //se a qt de linhas for par////********************************
    {
        k = 0; //contador destrutivo

        for(i = 0; i < l; i++)
        {
            for(j = 0; j < c; j++)
            {
                if( A[i][j]) //apenas celulas vivas (1) podem ser destruídas
                {
                    k++;
                    
                    if(k > qtdestruicao)
                    {
                        i = l;
                        break;
                    }

                    destruidas++;
                    A[i][j] = 0;
                }
                
            }
        }
    }
    else //se a qt de linhas for ímpar///////****************************
    {
        k = 0;

        for(j = 0; j < c; j++)
        {
            for (i = 0; i < l; i++)
            {
                if( A[i][j])
                {   
                    k++;

                    if(k > qtdestruicao)
                    {
                        j = c;
                        break;
                    }

                    destruidas++;
                    A[i][j] = 0;

                }
                
            }
        }
        
    }

    //printar************
    
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < c; j++)
        {
    
            while( space < j)
            {
                printf(" ");
                space++;
            }
            
            printf("%d", A[i][j]);

        }
        
        space = 0;

        printf("\n");
    }

    eliminacoesrestantes = abs(qtdestruicao - destruidas);
    
    ndestruidas = abs(celulasvivas - destruidas);

    printf("%d %d\n", eliminacoesrestantes, ndestruidas);



    return 0;
}
