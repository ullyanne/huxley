#include <stdio.h>

int maiorvalor(int x[])
{
    int maior = x[0];
    int i;

    for(i = 0; i < 6; i++)
    {
        if(x[i] >= maior)
        {
            maior = x[i];
        }
    }

    return maior;
}

int menorvalor(int y[])
{
    int menor = y[0];
    int i;

    for(i = 0; i < 6; i++)
    {
        if(y[i] <= menor)
        {
            menor = y[i];
        }
    }

    return menor;
}


int main()
{
    int valores[6], i;

    for(i = 0; i < 6; i++)
    {
        scanf("%d", &valores[i]);
    }

    printf("%d\n%d\n", menorvalor(valores), maiorvalor(valores));


    return 0;
}
