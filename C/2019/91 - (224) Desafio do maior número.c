#include <stdio.h>

int main()
{
    int n, i, aux, cont; //n é o tamanho da seq., i e cont são contadores

    int A[100];

    for(n = 0;  ; n++)
    {
        scanf("%d", &A[n]);
        
        if(A[n] == 0)
        {
            break;
        }
    }

    for(cont = 1; cont <= n; cont++)
    {
        for(i = 0; i < (n-1); i++)
        {
            if(A[i] > A[i+1])
            {
                aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
            }
        }
    }

    printf("%d\n", A[n-1]);


    return 0;
}
