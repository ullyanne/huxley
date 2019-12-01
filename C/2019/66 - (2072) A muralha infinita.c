#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() { 
    int n, i; //NUMERO DE DIAS
    int x = 0; //COORDENADAS
    int y = 0;
    int cont = 0;

    scanf("%d", &n);

    char direcao[n];

    int diff = y - x;

    int diff2 = x - y;

    if (n == 0)
    {
        printf("0\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {   
        scanf("%s", &direcao[i]);

        if (direcao[i] == 'C')
        {
            y++;
        }
        else 
        {
            x++;
        }
        
        diff = y - x;
        diff2 = x -y;

        if(i == 0) // CASO EXISTA APENAS UM CASO
        {
            cont = 0; 
        }
        
        else if(direcao[0] == 'C' )
        {
            if(diff2 == 1)
            {
                cont++;
                direcao[0] = 'D';
            }
        }
        else
        {
            if(diff == 1)
            {
                cont++;
                direcao[0] = 'C';
            }
        }



    }
    

    printf("%d\n", cont);
    return 0;
}
