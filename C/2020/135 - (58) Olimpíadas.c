#include <stdio.h>

struct medalhas
{
    int o, p, b;
    int id;
};

void iguais(struct medalhas paises[], int n)
{
    int cont, i;
    struct medalhas aux;
    
    //se a qt. de medalhas for igual, o que tiver menor id vence

    for(cont = 1; cont <= n; cont++)
    {
        for(i = 0; i < (n-1); i++)
        {
            if(paises[i].o == paises[i+1].o && paises[i].p == paises[i+1].p && paises[i].b == paises[i+1].b)
            {
                if(paises[i].id > paises[i+1].id)
                {
                    aux = paises[i];
                    paises[i] = paises[i+1];
                    paises[i+1] = aux;
                }

            }
        }
    }
}

void ordenar(struct medalhas paises[], int n)
{
    int cont, i;
    struct medalhas aux;
    
    for(cont = 1; cont <= n; cont++)
    {
        for(i = 0; i < (n-1); i++)
        {
            if(paises[i].b < paises[i+1].b) //come�a do menos significante
            {
                aux = paises[i];
                paises[i] = paises[i+1];
                paises[i+1] = aux;
            }

            if(paises[i].p < paises[i+1].p)
            {
                aux = paises[i];
                paises[i] = paises[i+1];
                paises[i+1] = aux;
            }

            if(paises[i].o < paises[i+1].o)
            {
                aux = paises[i];
                paises[i] = paises[i+1];
                paises[i+1] = aux;
            }
        }
    }
}

int main()
{
    int n, m, i, cont;

    scanf("%d%d", &n, &m);

    struct medalhas modali[m]; //serve para receber a entrada
    struct medalhas paises[n]; //contador de medalhas para cada id

    for(i = 0; i < n; i++) //preencher os ids e a qt inicial de medalhas 
    {
        paises[i].id = i+1;
        paises[i].o = 0;
        paises[i].p = 0;
        paises[i].b = 0;
    }
    
    for(i = 0; i < m; i++)
    {
        scanf("%d%d%d", &modali[i].o, &modali[i].p, &modali[i].b);
        
        paises[modali[i].o -1].o++; 
        //modali[i].o representa o id de um pa�s
        //-1 porque o array come�a do 0 e as ids come�am do 1
        //aumentar a quantidade de medalhas
        paises[modali[i].p -1].p++;
        paises[modali[i].b -1].b++;
    }

    ordenar(paises, n);
    iguais(paises, n); //caso haja empate em todas as qts. de medalhas

    for(i = 0; i < n; i++) //printar os ids j� ordenados
    {
        printf("%d\n", paises[i].id);
    }

    return 0;
}