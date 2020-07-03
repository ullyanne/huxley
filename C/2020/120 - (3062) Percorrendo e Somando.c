#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    int posicao[2];
    
    int qtcomandos;

    int soma = 0;

    scanf("%d%d", &n, &m);

    int matriz[n][m];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < 2; i++)
    {
        scanf("%d", &posicao[i]);
    }

    scanf("%d", &qtcomandos);

    int comandos[qtcomandos];

    i = posicao[0];
  
    j = posicao[1];

    for(k = 0; k < qtcomandos; k++)
    {
        scanf("%d", &comandos[k]);

        if(comandos[k] == 0)
        {
            i++;
            j--;

            if(i >= 0 && i < n && j >= 0 && j < m)
            {
   
                soma += matriz[i][j];
            }
            else
            {
                i--;
                j++;

                soma += matriz[i][j];
            }
        }
        else if(comandos[k] == 1)
        {
            i--;
            j--;

            if(i >= 0 && i < n && j >= 0 && j < m)
            {
                soma += matriz[i][j];
            }                 
            else
            {
                i++;
                j++;

                soma += matriz[i][j];
            }
        }
        else if(comandos[k] == 2)
        {
            i++;
            j++;

            if(i >= 0 && i < n && j >= 0 && j < m)
            {
                soma += matriz[i][j];
                 
            }
            else
            {
                i--;
                j--;
      
                soma += matriz[i][j];
            }
        }
        else if(comandos[k] == 3)
        {
            i--;
            j++;

            if(i >= 0 && i < n && j >= 0 && j < m)
            {
                soma += matriz[i][j];
                            
            }
            else
            {
                i++;
                j--;
 
                soma += matriz[i][j];
            }
        }
    }

    printf("%d\n", soma);

    return 0;
}