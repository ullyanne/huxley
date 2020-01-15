#include <stdio.h>

int main()
{
    int l, c;
    float matriz[3][3];

    float somatotal = 0;
    double media;
    float somadiagonal = 0;
    float maior;
    int delta;

    for(l = 0; l < 3; l++)
    {
        for(c = 0; c < 3; c++)
        {
            scanf("%f", &matriz[l][c]);
            
            if(c == 0 && l == 0)
            {
                maior = matriz[l][c];
            }
            
            somatotal += matriz[l][c];

            if(matriz[l][c] > maior)
            {  
                maior = matriz[l][c];
            }

            if(l == c)
            {
                somadiagonal += matriz[l][c];
            }

        }
    }

    if(maior > 0)
    {
        delta = 1;
    }
    else if(maior == 0)
    {
        delta = 0;
    }
    else
    {
        delta = -1;
    }

    media = somatotal/9;

    printf("%.2lf %.0f %d %.0f\n", media, maior, delta, somadiagonal);


    return 0;
}
