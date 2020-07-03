#include <stdio.h>
#include <string.h>

struct lista
{
    int codigo;
    char nome[50];
    double preco;
};

int main()
{
    int i, n, codigo, qt;
    double total = 0;

    scanf("%d", &n);

    struct lista produtos[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &produtos[i].codigo);
        getchar();

        fgets(produtos[i].nome, 50 , stdin);

        scanf("%lf", &produtos[i].preco);
    }

    while( scanf("%d", &codigo) && codigo != 0 )
    {
        scanf("%d", &qt);

        for(i = 0; i < n; i++)
        {   
            if(produtos[i].codigo == codigo)
            {   
                if(qt > 0)
                {
                    total += qt * produtos[i].preco;
                }
            }
        }
    }

    printf("%.2lf\n", total); 
    
    return 0;
}