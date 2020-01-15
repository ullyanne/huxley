#include <stdio.h>

int main()
{
    int n, c, l;

    scanf("%d", &n);

    int A[n][n];
    int B[n][n];
    int R[n][n];

    for(l = 0 ; l < n; l++)
    {
        for(c = 0; c < n; c++)
        {
            scanf("%d", &A[l][c]);
        }
    }

    for(l = 0 ; l < n; l++)
    {
        for(c = 0; c < n; c++)
        {
            scanf("%d", &B[l][c]);
        }
    }

    for(l = 0 ; l < n; l++)
    {
        for(c = 0; c < n; c++)
        {
            R[l][c]= A[l][c] + B[l][c];

            printf("%d ", R[l][c]);
        }

        printf("\n");
    }



    return 0;
    

}
