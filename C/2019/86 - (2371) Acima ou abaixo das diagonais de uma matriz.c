#include <stdio.h>
#include <string.h>

int main()
{
    char acima[] = "acima";
    char abaixo[] = "abaixo";
    char str[7];
    int r, limiar, ordem, l, c, soma;

    fgets(str, 7, stdin);

    r = strlen(str);
    str[r - 1] = '\0';

    scanf("%d", &limiar);
    scanf("%d", &ordem);

    int A[ordem][ordem]; //matriz dada pelo usu�rio

    for(l = 0; l < ordem; l++)
    {
        for(c = 0; c < ordem; c++)
        {
            scanf("%d", &A[l][c]);
        }
    }

    if( !strcmp(str, acima) )
    {
        for(l = 0; l < ordem; l++)
        {
            for(c = l+1; c < ordem; c++)
            {
                soma += A[l][c];
            }
        }
    }
    else
    {
        for(l = 0; l < ordem; l++)
        {
            for(c = 0; c < l; c++)
            {
                soma += A[l][c];
            }
        }
    }

    //printf("%d\n", soma);//

    if(soma > limiar)
    {
        printf("True\n");
    }
    else if(soma < limiar)
    {
        printf("False\n");
    }


    return 0;
}
