#include <stdio.h>

int main()
{
    char C[501] = "";
    char x = ' ';
    int i;
    int k = 1;

    fgets(C, 501, stdin);

    for(i = 1; i < 501; i++)
    {
        if(C[i] == x && C[i-1] != x)
        {
            k+=1;
        }

    }

    printf("%d\n", k);


    return 0;
}
