#include <stdio.h>

int main()
{
    char C[51];
    char x;
    int i;
    int k = 0;

    scanf("%s", C);

    scanf(" %c", &x);

    for(i = 0; i < 51; i++)
    {
        if(C[i] == x)
        {
            k+=1;
        }
    }

    printf("%d\n", k);


    return 0;
}
