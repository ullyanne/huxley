#include <stdio.h>
#include <string.h>

struct lista
{
    char nome[25];
    double preco;
};

void imprimir(struct lista itens[], int qt, double* dinheiro)
{
    int cont, i, contador = 0;
    struct lista aux;

    for(cont = 1; cont <= qt; cont++)
    {
        for(i = 0; i < (qt-1); i++)
        {
            if( itens[i].preco > itens[i+1].preco)
            {
                aux = itens[i];
                itens[i] = itens[i+1];
                itens[i+1] = aux;
            }
        }
    }
    
    for(i = 0; i < qt; i++)
    {
        if(*dinheiro - itens[i].preco >= 0)
        {
            contador++;
            *dinheiro -= itens[i].preco;
        }
    }

    for(cont = 1; cont <= contador; cont++)
    {
        for(i = 0; i < (contador-1); i++)
        {
            if( strcmp(itens[i].nome, itens[i+1].nome) > 0)
            {
                aux = itens[i];
                itens[i] = itens[i+1];
                itens[i+1] = aux;
            }
        }
    }

    for(i = 0; i < contador; i++)
    {
        printf("%s %.2lf\n", itens[i].nome, itens[i].preco);
    }
 
    printf("%.2lf\n", *dinheiro);
}

int main()
{
    double dinheiro;
    int qt;

    scanf("%lf", &dinheiro);
    scanf("%d", &qt);

    struct lista itens[qt];
    
    for(int i = 0; i < qt; i++)
    {
        scanf("%s %lf", itens[i].nome, &itens[i].preco);
    }

    imprimir(itens, qt, &dinheiro);




    return 0;
}