#include <stdio.h>

struct incendio
{
    int id;
    double temp;
    char fumaca;

};

int main()
{
    int testes, qt, i, k;
    double media;
    scanf("%d", &testes);


    for(k = 0; k < testes; k++)
    {
        scanf("%d", &qt);
        
        struct incendio sprink[qt];
        media = 0;

        printf("TESTE %d\n", k+1);

        for(i = 0; i < qt; i++)
        {
            scanf("%d%lf %c", &sprink[i].id, &sprink[i].temp, &sprink[i].fumaca);
            media += sprink[i].temp;
        }

        media = (media/qt);

        for(i = 0; i < qt; i++)
        {
            if(sprink[i].fumaca == 'S' || sprink[i].temp > (media*1.15) || sprink[i].temp >= 40 )
            {
                printf("%d\n", sprink[i].id);
            }
        }
    }



    return 0;
}