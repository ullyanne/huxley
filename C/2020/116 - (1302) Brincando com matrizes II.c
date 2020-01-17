#include <stdio.h>

int main()
{
    int matriz[3][3];
    
    float mediapositivos = 0;
    int positivos = 0;

    int menor;
    int delta;

    int somadiagonal = 0;

    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {   
            scanf("%d", &matriz[i][j]);
            
            if(matriz[i][j] > 0)
            {
                mediapositivos += matriz[i][j];
                positivos++;
            }

            if(i == 0 && j == 0)
            {
                menor = matriz[i][j];
            }

            if(matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
            
            if(i != j)
            {
                somadiagonal += matriz[i][j];
            }
        }
    }

    if(menor % 2 == 0)
    {
        delta = 1;
    }
    else
    {
        delta = 0;
    }

    printf("%.2f %d %d %d\n", mediapositivos/positivos, menor, delta, somadiagonal);


    return 0;
}
