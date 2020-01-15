#include <stdio.h>

int main()
{
    char C[7];
    int i, n;
    int xicaras = 0;
    int capsulas = 0;

    for (i = 0; i < 7; i++)
    {
        scanf("%d", &n);
        scanf(" %c", &C[i]);

        if(C[i] == 'p' || C[i] == 'P') //caixas pequenas
        {
            capsulas += n * 10;
        }
        else  //caixas grandes
        {
            capsulas += n * 16;
        }

      
    }

    xicaras = (capsulas * 2)/7;

    printf("%d\n%d\n", capsulas, xicaras);

    return 0;
}
