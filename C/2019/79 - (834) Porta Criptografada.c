#include <stdio.h>

int main()
{
    int A[4];
    int cont, aux, i;
    int r1, r2; //resposta 1 e 2

    for(i = 0; i < 4; i++)
    {
        scanf("%d", &A[i]);
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

    r1 = A[0] + A[1];
    r2 = A[0] + A[2];

    printf("%d%d\n", r1, r2);


    return 0;
}
