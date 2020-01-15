#include <stdio.h>

int main()
{
    int matriz[4][4];
    int l, c, k;

    while(scanf("%d", &k) && k != 0)
    {
        for(c = 0; c < 4; c++)
        {
            for(l = 0; l < 4; l++)
            {
                scanf("%d", &matriz[l][c]);

                if(l == c)
                {
                    matriz[l][c] *= k;
                }

            }
        }

        for(l = 0; l < 4; l++)
        {
            for(c = 0; c < 4; c++)
            {
                printf("%d ", matriz[l][c]);
            }

            printf("\n");
        }
    }


    return 0;
}
