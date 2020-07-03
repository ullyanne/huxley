#include <stdio.h>

int main()
{
    int n, m, i, j;

    scanf("%d%d", &n, &m);

    int matriz[n][m];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    int qtk, comk, ik, jk;


    for(j = 0; j < 2; j++)
    {  
        if(j != 0)
        {
            printf("\n");
        }
        
        ik = 0; 
        jk = 0;

        scanf("%d", &qtk);

        char c = matriz[ik][jk];
        printf("%c", c);

        for(i = 0; i < qtk; i++)
        {
            scanf("%d", &comk);

            if(comk == 0) //baixo, linha++
            {
                if(ik + 1 < n)
                {
                    if(matriz[ik+1][jk] != 35)
                    {
                        ik++;
                        char c = matriz[ik][jk];
                        printf("%c", c);
                    }
                }
            }
            else if(comk == 1)
            {
                if(ik - 1 >= 0)
                {
                    if(matriz[ik-1][jk] != 35)
                    {
                        ik--;
                        char c = matriz[ik][jk];
                        printf("%c", c);
                    }
                }
            }
            else if(comk == 2)
            {
                if(jk + 1 < m)
                {
                    if(matriz[ik][jk+1] != 35)
                    {
                        jk++;
                        char c = matriz[ik][jk];
                        printf("%c", c);
                    }
                }
            }
            else if(comk == 3)
            {
                if(jk - 1 >= 0)
                {
                    if(matriz[ik][jk-1] != 35)
                    {
                        jk--;
                        char c = matriz[ik][jk];
                        printf("%c", c);
                    }
                }
            }
        }
    }


    return 0;
}