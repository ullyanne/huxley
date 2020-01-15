#include <stdio.h>

void diadasemana(int i)
{       
    if(i == 0)
    {
        printf("DIA QUE MAIS PRODUZIU: DOMINGO\n");
    }
    else if(i == 1)
    {
        printf("DIA QUE MAIS PRODUZIU: SEGUNDA\n");
    }
    else if(i == 2)
    {
        printf("DIA QUE MAIS PRODUZIU: TERCA\n");
    }
    else if(i == 3)
    {
        printf("DIA QUE MAIS PRODUZIU: QUARTA\n");
    }
    else if(i == 4)
    {
        printf("DIA QUE MAIS PRODUZIU: QUINTA\n");
    }
    else if(i == 5)
    {
        printf("DIA QUE MAIS PRODUZIU: SEXTA\n");
    }
    else if(i == 6)
    {
        printf("DIA QUE MAIS PRODUZIU: SABADO\n");
    }

}

int main()
{
    int P[7];
    int L[7];
    int i, dia;
    int contpro = 0;
    int contli = 0;


    //scannear os valores
    for(i=0; i < 7; i++)
    {
        scanf("%d", &P[i]);
        scanf("%d", &L[i]);

        //checar se atingiu a meta
        if(P[i] >= 5)
        {
            contpro++;
        }

        if(L[i] >= 100)
        {
            contli++;
        }

        
    }
    
    int diaprodutivo = L[0];
    
    for(i = 0; i < 7; i++)
    {    
        //dia que mais produziu linhas de codigo
        if(L[i] >= diaprodutivo)
        {
            dia = i;
            diaprodutivo = L[i];
        }

    }

    printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\n", contpro);
    printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\n", contli);
    
    diadasemana(dia);


    return 0;

}


