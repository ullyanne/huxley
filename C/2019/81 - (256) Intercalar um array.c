#include <stdio.h>

int main()
{
    int n, i;

    scanf("%d", &n);

    int A[n];
    int B[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for(i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }

    for(i = 0; i < n; i++)
    {
        printf("%d\n%d\n", A[i], B[i]);
    }


    return 0;
}
