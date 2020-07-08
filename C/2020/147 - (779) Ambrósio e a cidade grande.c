#include <stdio.h>

typedef struct rodov
{
    int destino;
    int partida;
}onib;

int main()
{
    int n, i, j, time = 0;

    scanf("%d", &n);

    onib horas [n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &horas[i].destino);
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d", &horas[i].partida);
    }

    time += horas[0].destino;

    for(i = 1; i < n; i++)
    {   
        //tempo de espera até o próximo ônibus chegar (partida) + tempo de viagem
        if(time <= horas[i].partida)
            time += (horas[i].partida - time) + horas[i].destino;
        else
            //encontrando múltiplos do tempo de partida até ficar maior que o tempo acumulado
            for(j = 2;  ; j++)
                if(time <= (j * horas[i].partida))
                {   
                    time += ((horas[i].partida * j) - time) + horas[i].destino;
                    break;
                }
    }

    printf("time: %d\n", time);
    return 0;
}