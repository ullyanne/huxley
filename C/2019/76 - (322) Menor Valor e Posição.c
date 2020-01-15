#include <stdio.h>

int main()
{
    int N, cont, i, aux, menor;
    int posicao = 0;
    scanf("%d", &N);

    int A[N];

    for(i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    //posicao

    menor = A[0];

    for(i = 1; i < N; i++)
    {
        if(A[i] < menor)
        {
            menor = A[i];
            posicao = i;
        }
    }


    for(cont = 1; cont <= N; cont++)
    {
        for(i = 0; i < (N-1); i++)
        {
            if(A[i] > A[i+1])
            {   
                aux = A[i+1];
                A[i+1] = A[i];
                A[i] = aux;
            }
        }
    }

    printf("Menor valor: %d\nPosicao: %d\n", A[0], posicao);

    return 0;
}
