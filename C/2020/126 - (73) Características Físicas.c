#include <stdio.h>

struct pessoas
{
    int idade;
    char sexo, cabelo, olhos;
};

int main()
{
    struct pessoas a[100];
    int total = 0;
    int condicao = 0;
    int velho, i;
    double porcentagem;
    

    for(i = 0; scanf("%d", &a[i].idade) && a[i].idade != -1 && i < 100; i++)
    {
        total++;
        
        if(i == 0)
        {
            velho = a[0].idade;
        }
        
        if(a[i].idade > velho)
        {
            velho = a[i].idade;
        }

        scanf(" %c %c %c", &a[i].sexo, &a[i].cabelo, &a[i].olhos);

        if(a[i].sexo == 'f' && a[i].idade >= 18 && a[i].idade <= 35 && a[i].cabelo == 'l' && a[i].olhos == 'v')
        {
            condicao++;
        }

    }

    porcentagem = ((double) condicao/total) * 100;
    printf("Mais velho: %d\nMulheres com olhos verdes, loiras com 18 a 35 anos: %.2lf%%", velho, porcentagem);

    return 0;
}