#include <stdio.h>

int main()
{
    int n, total, i, k;
    int total2 = 0;

    scanf("%d", &n);

    int A[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    total = A[0]; //acumula só 1 array

    for(i = 1; i < n; i++)
    {
        total2+= A[i]; //acumula todos os arrays
    }

    for(i = 1; total != total2 ; i++)
    {
        total += A[i]; //aumentando arrays para igualar
        total2 -= A[i]; //diminuindo arrays para igualar

        k = i+1; //parte que será feita a divisão
    }
    
    printf("%d\n", k);

    return 0;
}
