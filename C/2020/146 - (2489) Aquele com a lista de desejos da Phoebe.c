#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, qt, cont = 0;
    scanf("%d", &qt);
    getchar();

    char str1[qt][500];

    for(i = 0; i < qt; i++)
    {
        scanf("%[^\n]", str1[i]);
        getchar();
    }

    int qt2;
    scanf("%d", &qt2);
    getchar();

    char str2[qt2][500];

    for(i = 0; i < qt2; i++)
    {
        scanf("%[^\n]", str2[i]);
        getchar();
    }

//busca para ver quantos são iguais
    for(i = 0; i < qt2; i++)
        for(j = 0; j < qt; j++)
            if(strcmp(str2[i], str1[j]) == 0)
                cont++;

    if(cont == qt)
        printf("Smelly Cat, Smelly Cat, what are they feeding you?\n");
    else
    {
        printf("Ainda falta(m) %d objetivo(s)!\n", qt-cont);

        //printar quantos não são iguais
        for(i = 0; i < qt2; i++)
            for(j = 0; j < qt; j++)
                if(strcmp(str1[j], str2[i]) != 0)
                    puts(str1[j]);
    }

    return 0;
}