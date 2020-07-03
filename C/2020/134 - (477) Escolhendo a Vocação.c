#include <stdio.h>

struct ficha
{
    int forca, intel, destr, furt, kg;
};

int main()
{
    struct ficha rpg;
    int i;

    scanf("%d%d%d%d%d", &rpg.forca, &rpg.intel, &rpg.destr, &rpg.furt, &rpg.kg);
    
    if(rpg.forca > 5 && rpg.destr > 5 && rpg.kg > 5)
    {
        printf("Knight\n");
    }
    else if(rpg.forca < 5 && rpg.intel > 5 && rpg.furt > 5 && rpg.kg < 5)
    {
        printf("Mage\n");
    }
    else if(rpg.forca > 5 && rpg.intel > 5 && rpg.destr > 5 && rpg.furt > 5 && rpg.kg < 5)
    {
        printf("Paladin\n");
    }
    else if(rpg.forca > 10 && rpg.intel < 5 && rpg.destr < 5 && rpg.furt < 5 && rpg.kg > 5)
    {
        printf("Orc\n");
    }

    return 0;
}