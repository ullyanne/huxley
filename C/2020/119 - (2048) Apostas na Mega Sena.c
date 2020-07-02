#include <stdio.h>

int main()
{
    int qtapostas;
    int i, j, k;
    char charman;

    scanf("%d", &qtapostas);

    int apostas[qtapostas][10];
    int tamanho[qtapostas][1];

    int resultado[6];

    int win;
    int vencedores = 0;

    for(i = 0, j = 0; i < qtapostas; )
    {

        scanf("%d", &apostas[i][j]);

        charman = getchar();

        if(charman == '\n')
        {
            tamanho[i][0] = j+1;
            i++;
            j = 0;
        }
        else
        {
            j++;
        }
    
    }

    for(i = 0; i < 6; i++)
    {
        scanf("%d", &resultado[i]); 

    }

    for(i = 0; i < qtapostas; i++)
    {
        win = 0;

        for(j = 0, k = 0; j < tamanho[i][0]; j++)
        {   
           
            if(apostas[i][j] == resultado[k])
            {  
                k++;
                win++;

            }
            else if(resultado[k] < apostas[i][0])
            {
                break;
            }

        }

        if(win == 6)
        {
            vencedores++;
        }
    }
    
    printf("Total de ganhadores: %d\n", vencedores);

    return 0;    
}