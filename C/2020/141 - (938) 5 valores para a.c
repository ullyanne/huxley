#include <stdio.h>

int main()
{
    float a;
    int neg = 0;

    for(int i = 0; i < 5; i++)
    {   printf("Digite um valor:\n");
        scanf("%f", &a);

        if(a < 0)
            neg++;
    }

    printf("Foram digitados %d numeros negativos", neg);

    return 0;
}