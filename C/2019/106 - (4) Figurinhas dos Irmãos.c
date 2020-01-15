#include <stdio.h>

int main()
{
    int nfigs, i, cont, aux, maiorsoma;
    
    int pares = 0; //número de figuras pares
    int impares = 0;

    int somapar = 0; //soma de todas as séries de figuras pares
    int somaimpar = 0;

    scanf("%d", &nfigs);

    int figuras[nfigs];

    for(i = 0; i < nfigs; i++)
    {
        scanf("%d", &figuras[i]);

        if(figuras[i] % 2 == 0)
        {
            pares++;
        }
        else
        {
            impares++;
        }
    }


    //ordenar para ficar mais fácil somar sem contar séries repetidas

    for(cont = 1; cont <= nfigs; cont++)
    {
        for(i = 0; i < (nfigs - 1); i++)
        {
            if(figuras[i] > figuras[i+1])
            {
                aux = figuras[i];
                figuras[i] = figuras[i+1];
                figuras[i+1] = aux;
            }
        }
    }


    //soma de séries de figuras

    for(i = 0; i < nfigs; i++)
    {
        if(i == 0)
        {
            if(figuras[i] % 2 == 0)
            {
                somapar += figuras[i];
            }
            else
            {
                somaimpar += figuras[i];
            }
        }
        else
        {
            if(figuras[i] != figuras[i-1])
            {
                if(figuras[i] % 2 == 0)
                {
                    somapar += figuras[i];
                }
                else
                {
                    somaimpar += figuras[i];
                }
            }
        }
    }

    maiorsoma = somapar;

    if(somaimpar > maiorsoma)
    {
        maiorsoma = somaimpar;
    }


    printf("%d\n%d\n%d\n", pares, impares, maiorsoma);

    return 0;
}
