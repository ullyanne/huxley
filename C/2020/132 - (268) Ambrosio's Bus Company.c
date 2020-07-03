#include <stdio.h>
#include <string.h>

struct viagem
{
    int num, dia, mes, ano, hora, min, poltr, idade;
    char de[50], para[50], nome[50];
};

int main()
{
    struct viagem futura[43];
    int i, j;
    float mediaidade = 0;

    for(i = 0; scanf("%d", &futura[i].num) && futura[i].num != -1 && i < 44; i++)
    {
        scanf("%d", &futura[i].dia);
        getchar();
        scanf("%d", &futura[i].mes);
        getchar();
        scanf("%d", &futura[i].ano);

        getchar();
        fgets(futura[i].de, 50 , stdin);
        futura[i].de[strlen(futura[i].de) -1] = '\0';
        fgets(futura[i].para, 50, stdin);
        futura[i].para[strlen(futura[i].para) -1] = '\0';

        scanf("%d", &futura[i].hora);
        getchar();
        scanf("%d", &futura[i].min);

        scanf("%d", &futura[i].poltr);
        scanf("%d", &futura[i].idade);
        mediaidade += futura[i].idade;

        getchar();

        fgets(futura[i].nome, 50, stdin);
        futura[i].nome[strlen(futura[i].nome) -1] = '\0';
    }

    mediaidade = mediaidade/i;

    for(j = 0; j < i; j++)
    {
        if(mediaidade < futura[j].idade && futura[j].poltr % 2 == 0)
        {
            printf("%s\n", futura[j].nome);
        }
    }

    return 0;
}