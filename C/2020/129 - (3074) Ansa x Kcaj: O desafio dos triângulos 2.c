#include <stdio.h>

int dir(int base, int i, int j, int n, int matriz[][n], int value)
{   
    int aux, soma;
    
    int exti1 = i-1;
    int exti2 = i+1;

    int extj = j-1;

    for(aux = 3; aux <= base; aux+=2, exti1--, exti2++, extj--)
    {
        if( exti1 >= 0 && exti2 < n && extj >= 0)
        {   
            soma = 0;

            if(matriz[exti1][extj] == value && matriz[exti2][extj] == value)
            {
                for(int aux2 = exti2-1; aux2 > exti1; aux2--)
                {
                    if(matriz[aux2][extj] == value)
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

int esq(int base, int i, int j, int n, int matriz[][n], int value)
{   
    int aux, soma;
    
    int exti1 = i-1;
    int exti2 = i+1;

    int extj = j+1;

    for(aux = 3; aux <= base; aux+=2, exti1--, exti2++, extj++)
    {
        if( exti1 >= 0 && exti2 < n && extj < n)
        {   
            soma = 0;

            if(matriz[exti1][extj] == value && matriz[exti2][extj] == value)
            {
                for(int aux2 = exti2-1; aux2 > exti1; aux2--)
                {
                    if(matriz[aux2][extj] == value)
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

int baixo(int base, int i, int j, int n, int matriz[][n], int value)
{   
    int aux, soma;
    int exti = i-1;
    int extj1 = j-1;
    int extj2 = j+1;

    for(aux = 3; aux <= base; aux+=2, exti--, extj1--, extj2++)
    {
        if( exti >= 0 && extj1 >= 0 && extj2 < n )
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

int cima(int base, int i, int j, int n, int matriz[][n], int value)
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
    int t, k;

    scanf("%d", &t);

    for(k = 0; k < t; k++)
    {
        if(k != 0)
        {
            printf("\n");
        }
        
        printf("Caso %d:\n", k+1);

        int n, i, j, aux, value;
    
        int triang1, triang0;

        scanf("%d", &n);

        int matriz[n][n];

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }

        for(value = 1; value >= 0; value--)
        {
            for(aux = 3; aux <= n; aux+=2)
            {
                triang1 = 0;
                triang0 = 0;

                for(i = 0; i < n; i++)
                {
                    for(j = 0; j < n; j++)
                    {
                        if(matriz[i][j] == value)
                        {   
                            if(dir(aux, i, j, n, matriz, value))
                            {
                                if(value)
                                {
                                    triang1++;
                                }
                                else
                                {
                                    triang0++;
                                }
                            }

                            if(esq(aux, i, j, n, matriz, value))
                            {
                                if(value)
                                {
                                    triang1++;
                                }
                                else
                                {
                                    triang0++;
                                }
                            }

                            if(baixo(aux, i, j, n, matriz, value))
                            {
                                if(value)
                                {
                                    triang1++;
                                }
                                else
                                {
                                    triang0++;
                                }
                            }

                            if(cima(aux, i, j, n, matriz, value))
                            {
                                if(value)
                                {
                                    triang1++;
                                }
                                else
                                {
                                    triang0++;
                                }
                            }  
                        }
                    }
                }

                if(triang1 != 0)
                {
                    printf("%d triangulos de base %d formados por 1\n", triang1, aux);
                } 
                
                if(triang0 != 0)
                {
                    printf("%d triangulos de base %d formados por 0\n", triang0, aux);
                }
        
            }
        }
    }

    return 0;
}