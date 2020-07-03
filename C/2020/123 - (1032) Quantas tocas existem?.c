#include <stdio.h>

int main()
{
    int n, i, j;

    int tocas = 0;
    int cont = 0;

    scanf("%d", &n);

    int buracos[n];
    int visitados[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &buracos[i]);
        visitados[i] = 0;
        
    }

    for(i = 0; ;)
    {
        if(visitados[i] != 1)
        {
            visitados[i] = 1;
            
            i = buracos[i];
        }
        else
        {      
            tocas++;
            cont = 0;
            for(j = 0; j < n; j++)
            {
                if(visitados[j] == 1)
                {
                    cont++;

                    if(cont == n) //se todos j� forem visitados
                    {
                        printf("%d\n", tocas);
                        return 0;
                    }
                }

            }
                

            for(j = 0; j < n ; j++)
            {
                if(visitados[j] == 0)
                {
                    i = j;
                    break;
                }
            }
        }
    }

    return 0;
}