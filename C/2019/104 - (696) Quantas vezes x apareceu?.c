#include <stdio.h>

int main()
{
    int numeros[10];
    int busca, i;
    int contabusca = 0;

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &numeros[i]);
    }

    scanf("%d", &busca);

    for(i = 0; i < 10; i++)
    {
        if(numeros[i] == busca)
        {
            contabusca++;
        }
    }

    printf("%d\n", contabusca);


    return 0;
}
