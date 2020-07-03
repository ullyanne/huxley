#include <stdio.h>

int main()
{
    int n, d, i, j, aux;

    scanf("%d%d", &n, &d);

    int num[n];
    int ord[n];

//scan e preenchendo com -1
    for(i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        
        ord[i] = -1;
    }
    

//preenchendo o array com quem atende o requisito
    for(i = 0, j = 0; i < n; i++)
        if(num[i] % 10 == d)
        {
            ord[j] = num[i];
            j++;
        }

//bubble sort
    for(i = 0; i < n; i++)
    {   
        for(j = 0; j < (n-1); j++)
        {
            if(ord[j] < ord[j+1])
            {   aux = ord[j];
                ord[j] = ord[j+1];
                ord[j+1] = aux;
            }
        }
    }

    for(i = 4; i >= 0; i--)
            printf("%d\n", ord[i]);

    return 0;
}