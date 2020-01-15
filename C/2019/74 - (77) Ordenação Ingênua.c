#include <stdio.h>

int main()
{
    int n, i, aux, cont;

    scanf("%d", &n);

    int Z[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &Z[i]);
    }

    for(cont = 1; cont <= n; cont++)
    {
        for(i = 0; i < (n-1); i++)
        {
            if(Z [i] > Z[i+1])
            {
                aux = Z[i];
                Z[i] = Z[i+1];
                Z[i+1] = aux;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        
        printf("[%d]", Z[i]);
        
        if( i == (n-1) )
        {
            printf("\n");
        }
       
    }

    return 0;
}
