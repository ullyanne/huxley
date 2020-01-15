#include <stdio.h>

int main()
{
    int A[5];
    int i, cont, aux;

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
    }

    for(cont = 1; cont <= 5; cont++)
    {
        for(i = 0; i < 4; i++)
        {
            if(A[i] > A[i+1])
            {
                aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
            }
        }
    }

    printf("%d\n%d\n%d\n", A[0], A[2], A[4]);




    return 0;
}
