#include <stdio.h>
#include <string.h>

#define RUN 1

typedef struct dic
{
    char nome[30];
    char objs[3][30];
}dici;

int main()
{
    int qt, i, j;

//respostas do usuário
    char name[30];
    char obj[30];

    scanf("%d", &qt);

//dicionário (respostas corretas)
    dici lista[qt];

    for(i = 0; i < qt; i++)
    {
        scanf("%s", lista[i].nome);

        for(j = 0; j < 3; j++)
            scanf("%s", lista[i].objs[j]);
    }
//fim de scan do dicionário

    while(RUN)
    {
//entrada do usuário
        scanf("%s", name);

        if(strcmp(name, "FIM") == 0)
            break;

//busca
        for(i = 0; i < qt; i++)
            //o nome está na lista?
            if(strcmp(name, lista[i].nome) == 0)
            {
                scanf("%s", obj);

                //o objeto está na lista?
                for(j = 0; j < 3; j++)
                {
                    if(strcmp(obj, lista[i].objs[j]) == 0)
                    {   printf("Uhul! Seu amigo secreto vai adorar\n");
                        break;
                    }

                    if(j == 2 && strcmp(obj, lista[i].objs[j]) != 0)
                        printf("Tente Novamente!\n");
                }
                break;
            }
    }

    return 0;
}