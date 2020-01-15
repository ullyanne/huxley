#include <stdio.h>

int main()
{
    int n, c, i; //n. de leituras e capacidade + contador
    int k = 0; //sinalizador
    int acumulador = 0;
    
    scanf("%d%d", &n, &c);

    int S[n]; //saídas e entradas
    int E[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &S[i], &E[i]);
        acumulador = (acumulador - S[i] + E[i]);

        if(acumulador > c) //se o acumulador for maior que a capacidade
        {
            k = 1;
        }
    }

    if(k == 1)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }



    return 0;
}
