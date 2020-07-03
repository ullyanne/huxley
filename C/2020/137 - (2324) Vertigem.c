#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados
{
    int movi, pts;
};

struct mapa
{   
    char nome[101];
    int l, c;
    struct dados matriz[101][101];
};

int palindromo(int k, struct mapa mapas[])
{
    int i, j;
    char invertido[strlen(mapas[k].nome) + 1];

    invertido[strlen(mapas[k].nome)] = '\0';

    for(j = 0, i = strlen(mapas[k].nome) - 1; i >= 0 ; j++, i--)
    {
        invertido[j] = mapas[k].nome[i];
    }

    if(strcmp(invertido, mapas[k].nome) == 0)
    {
        return 1;
    }

    return 0;
}

void posicao(int k, int* contador, int** posi, int** posj, struct mapa mapas[])
{
    int i, j;
    int aux = *contador;

    if(aux > (mapas[k].l * mapas[k].c) -1)
    {
        aux = aux % (mapas[k].l * mapas[k].c);
    }

    for(i = 0; i < mapas[k].l; i++)
    {
        for(j = 0; j < mapas[k].c; j++)
        {
            if( (i * mapas[k].c) + j == aux)
            {
                **posi = i;
                **posj = j;
                i = mapas[k].l;
                break;
            }
        }
    }

}

void percorrer
(int k, int* pts, int* contador, int* posi, int* posj, struct mapa mapas[])
{
    int i, j;
   
    for(i = *posi, j = *posj; ;  )
    {
        if(i == mapas[k].l -1 && j == mapas[k].c -1)
        {
            *contador += mapas[k].matriz[i][j].pts;
            *(pts+k) += mapas[k].matriz[i][j].pts;

            if(palindromo(k, mapas))
            {
                *contador += pts[k];
                pts[k] *= 2;
            }

            break;
        }
        
        if(mapas[k].matriz[i][j].movi == 0)
        {
            *contador += mapas[k].matriz[i][j].pts;
            *(pts+k) += mapas[k].matriz[i][j].pts;

            if(i - 1 < 0)
            {
                i = mapas[k].l - 1;
            }
            else
            {
                i--;
            }
        
        }

        
        if(mapas[k].matriz[i][j].movi == 1)
        {
            *contador += mapas[k].matriz[i][j].pts;
            *(pts+k) += mapas[k].matriz[i][j].pts;

            if(i + 1 > mapas[k].l - 1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
            
        }

        if(mapas[k].matriz[i][j].movi == 2)
        {
            *contador += mapas[k].matriz[i][j].pts;
            *(pts+k) += mapas[k].matriz[i][j].pts;

            if(j - 1 < 0)
            {
                j = mapas[k].c - 1;
            }
            else
            {
                j--;
            }   
        }

        if(mapas[k].matriz[i][j].movi == 3)
        {
            *contador += mapas[k].matriz[i][j].pts;
            *(pts+k) += mapas[k].matriz[i][j].pts;

            if(j + 1 > mapas[k].c - 1)
            {
                j = 0;
            }
            else
            {
                j++;
            }

        }
        
        if(mapas[k].matriz[i][j].movi == 4)
        {
            if(palindromo(k, mapas))
            {
                *contador += pts[k];
                pts[k] *= 2;
            }
            
            k = mapas[k].matriz[i][j].pts;
            
            posicao(k, contador, &posi, &posj, mapas);
            i = *posi;
            j = *posj;

        }
        
    }
}

int main()
{
    int qt, k, i, j;

    scanf("%d", &qt);

    int* pts = (int*) calloc(qt, sizeof(int));
    int contador = 0, posi = 0, posj = 0;

    struct mapa mapas[qt];
    
    for(k = 0; k < qt; k++)
    {
        scanf("%d%d", &mapas[k].l, &mapas[k].c);
        scanf("%s", mapas[k].nome);

        for(i = 0; i < mapas[k].l; i++)
        {
            for(j = 0; j < mapas[k].c; j++)
            {
                scanf("%d", &mapas[k].matriz[i][j].movi);
                getchar();
                scanf("%d", &mapas[k].matriz[i][j].pts);
            }
        }
    }

    percorrer(0, pts, &contador, &posi, &posj, mapas);
    
    printf("%d\n", contador);

    for(i = 0; i < qt; i++)
    {
        printf("%s %d\n", mapas[i].nome, pts[i]);
    }

    free(pts);
    
    return 0;
}