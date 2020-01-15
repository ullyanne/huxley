#include <stdio.h>

int main()
{
    int x, y, i;
    int contx; //verifica se o pacote de números chegou até x
    
    int j = 0; //apenas para pôr espaço
    int k = 0; //apenas para pôr espaço

    scanf("%d%d", &x, &y);

    for(i = 1, contx = 1; i <= y; i++, contx++) 
    //i = números da série
    //depois o i é somado com o incremento até chegar no número y
    {   
        while(k > j)
        {
            printf(" ");
            j++;
        }   

        printf("%d", i);

        k++;

        if(contx == x)
        {
            printf("\n");
            contx = 0;
            k = 0;
            j = 0;
        }

    }

    return 0;
}
