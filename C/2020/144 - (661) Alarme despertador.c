#include <stdio.h>
#define RUN 1

void virada(int* m, int* h, int* cont)
{
    if(m[0] != 0)
    {
        //quanto falta pra completar 1h?
        *cont += (60 - m[0]);
        //add 1h, vendo quanto falta pra 0:00 e depois convertendo pra minutos
        *cont += (24 - (1 + h[0])) * 60;
    }
    else
    {   
        //se os minutos estiverem zerados, não precisa completar
        *cont += (24 - h[0]) * 60;
    }
    
    //como a hora vai estar 00:00, só precisa adicionar h[1] (convertido) e os m[1]
    *cont += (h[1] * 60) + m[1];
}

int main()
{
    //horas e minutos
    int h[2];
    int m[2];

    int cont;

    while(RUN)
    {
        cont = 0;

        for(int i = 0; i < 2; i++)
        {
            scanf("%d", &h[i]);
            scanf("%d", &m[i]);
        }

        //condição pra parar o programa
        if(h[0] == 0 & h[1] == 0 & m[0] == 0 & m[1] == 0)
            return 0;

        //sem precisar virar o dia
        if(h[0] < h[1])
        {
            cont += (h[1] - h[0]) * 60;

            if(m[1] >= m[0])
                cont += m[1] - m[0];
            else 
                cont -= m[0] - m[1];
        }
        else if(h[0] == h[1])
        {
            if(m[1] >= m[0])
                cont += m[1] - m[0];
            else
                //significa que precisa virar o dia (1h05 - 1h03)
                virada(m, h, &cont);
        }
        else
            //se h[0] > h[1]
            //virada do relógio
            virada(m, h, &cont);

        printf("%d\n", cont);
    }

    return 0;
}