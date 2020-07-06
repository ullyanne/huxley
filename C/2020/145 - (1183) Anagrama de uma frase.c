#include <stdio.h>
#include <string.h>

void criar(char* str, char* anagr)
{
    int j, i;

    for(i = 0, j = 0; i < strlen(str); i++)
        //tudo, menos ' ', ',', '?', '!', '.'
        if(str[i] != 32 && str[i] != 33 & str[i] != 46 && str[i] != 44 && str[i] != 63)
        {
            //transformando maiúsculas em minúsculas
            if(str[i] >= 65 && str[i] <= 90)
                anagr[j] = str[i] + 32;
            //acentos em caracteres minúsculos
            else if(str[i] == 135 || str[i] == 130 || str[i] == 160 || str[i] == 136 || str[i] == 147 || str[i] == 161 || str[i] == 162)
                anagr[j] = str[i];
            //transformando acentos em caracteres maiúsculos em minúsculos
            else if(str[i] == 144)
                anagr[j] = str[i] - 14;
            else if(str[i] == 128)
                anagr[j] = str[i] + 7;
            else if(str[i] == 210)
                anagr[j] = str[i] - 74;
            else if(str[i] == 226)
                anagr[j] = str[i] - 79;
            else if(str[i] == 181)
                anagr[j] = str[i] - 21;
            else if(str[i] == 214)
                anagr[j] = str[i] - 53;
            else if(str[i] == 224)
                anagr[j] = str[i] - 62;
            //todo o resto
            else
                anagr[j] = str[i];
            //só avança se não for ' ', ',', '?', '!', '.'
            j++;
        }
}

int main()
{
    char str1[100];
    char str2[100];

    //para manipular as strings anteriores
    char anagr1[100] = "";
    char anagr2[100] = "";
    char aux;

    scanf("%[^\n]", str1);
    getchar();
    scanf("%[^\n]", str2);

    criar(str1, anagr1);
    criar(str2, anagr2);

    if(strlen(anagr1) != strlen(anagr2))
    {   
        printf("False\n");
        return 0;
    }
    else if(strcmp(anagr1, anagr2) == 0)
    {
        printf("True\n");
        return 0;
    }
    else
    {
        //bubble sort
        for(int i = 0; i < strlen(anagr1); i++)
            for(int j = 0; j < strlen(anagr1)-1; j++)
            {
                if(anagr1[j] > anagr1[j+1])
                {
                    aux = anagr1[j];
                    anagr1[j] = anagr1[j+1];
                    anagr1[j+1] = aux;
                }
                
                if(anagr2[j] > anagr2[j+1])
                {
                    aux = anagr2[j];
                    anagr2[j] = anagr2[j+1];
                    anagr2[j+1] = aux;
                }
            }
    }

    if(strcmp(anagr1, anagr2) == 0)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}