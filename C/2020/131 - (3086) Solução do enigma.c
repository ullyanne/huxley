#include <stdio.h>

int main()
{
    int n, m, i, j;
    int soma;
    int cont = 0;
    int total = 0;

    scanf("%d%d", &n, &m);

    int matriz[n][m];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    int a[4];
    int l, aux;

        for(i = 0; i < n-1; i++)
        {
            for(j = 0; j < m-1; j++)
            {
                if(j+1 < m && i+1 < n)
                {
                   a[0] = matriz[i][j];
                   a[1] = matriz[i][j+1];
                   a[2] = matriz[i+1][j];
                   a[3] = matriz[i+1][j+1];
                }

                for(int cont = 1; cont <= 4; cont++)
                {
                    for(l = 0; l < 3; l++)
                    {
                        if(a[l] > a[l+1])
                        {
                            aux = a[l];
                            a[l] = a[l+1];
                            a[l+1] = aux;
                        }
                    }
                }

                if(a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 3)
                {
                    total++;
                }
            }//
        }//


    printf("%d\n", total);

    return 0;
}