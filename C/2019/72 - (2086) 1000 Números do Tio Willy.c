#include <stdio.h>

int main()
{
    int W[1000];
    int N, i;
    int k = 0;

    for( ; ; )
    {
        for(i= 0 ; i < 1000; i++)
        {
            scanf("%d", &W[i]);

            if(W[0] == -1) //condi��o de parada
            {
               return 0;
            }

        }

        scanf("%d", &N);

        for(i = 0; i < 1000; i++)
        {
            if(W[i] == N)
            {
                k++;
            }
        }


        printf("%d appeared %d times\n", N, k);

        k = 0;

    }    

    


    return 0;
}
