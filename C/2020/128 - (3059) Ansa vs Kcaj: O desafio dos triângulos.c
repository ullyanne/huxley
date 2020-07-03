#include <stdio.h>

int verificar(int base, int i, int j, int n, int matriz[][n], int value)
{   
    
    int aux, soma;
    int exti = i+1;
    int extj1 = j-1;
    int extj2 = j+1;

    for(aux = 3; aux <= base; aux+=2, exti++, extj1--, extj2++)
    {
        if( exti < n && extj1 >= 0 && extj2 < n )
        {   
            soma = 0;

            if(matriz[exti][extj1] == value && matriz[exti][extj2] == value)
            {
                for(int aux2 = extj1+1; aux2 < extj2; aux2++)
                {
                    if(matriz[exti][aux2] == value)
                    {
                        soma++;
                    }
                }

                if(soma != aux-2)
                {
                    return 0;
                }

            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }

    }
    
    return 1;
}

int main()
{
    int t, i, k;

    scanf("%d", &t);

    for(k = 0; k < t; k++)
    {
        int b, n, i, j;
        
        int triang1 = 0;
        int triang0 = 0;

        scanf("%d%d", &b, &n);

        int matriz[n][n];

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }
    
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(matriz[i][j] == 1)
                {
                    if(verificar(b, i, j, n, matriz, 1))
                    {
                        triang1++;
                    }
                }
                else if(matriz[i][j] == 0)
                {
                    if(verificar(b, i, j, n, matriz, 0))
                    {
                        triang0++;
                    }
                }
            }
        }
        
        printf("Caso %d:\n%d triangulos formados por 1\n%d triangulos formados por 0\n", k+1, triang1, triang0);
    }

    return 0;
}