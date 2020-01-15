#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    int seq[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &seq[i]);
    }

    for(i = (n-1), j = (n-1) ; i >= 0 ; i--)
    {   
        
        while(j > i)
        {
            printf(" ");
            j--;
        }

        printf("%d", seq[i]);

        if(i == 0)
        {
            printf("\n");
        }
    }


    return 0;
}
