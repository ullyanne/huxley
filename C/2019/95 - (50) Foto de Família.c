#include <stdio.h>

int main()
{
    float A[4];
    float aux;
    int i, cont;

    for(i = 0; i < 4; i++)
    {
        scanf("%f", &A[i]);
    }

    for(cont = 1; cont <= 4; cont++)
    {
        for(i = 0; i < 3; i++)
        {
            if(A[i] > A[i+1])
            {
                aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
            }
        }
    }

    printf("%.2f\n%.2f\n%.2f\n%.2f\n", A[0], A[2], A[3], A[1]);

    return 0;
}
