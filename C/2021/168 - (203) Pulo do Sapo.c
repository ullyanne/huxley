#include <stdio.h>
#include <stdlib.h>

void checarfrente(int* array, int inicial, int distancia, int pedras)
{
    if(inicial + distancia < pedras)
    {
        array[inicial+distancia] = 1;
        checarfrente(array, inicial+distancia, distancia, pedras);
    }
}

void checaratras(int* array, int inicial, int distancia)
{
    if(inicial - distancia >= 0)
    {
        array[inicial-distancia] = 1;
        checaratras(array, inicial-distancia, distancia);
    }
}

int main()
{
    int pedras, sapos, inicial, distancia;

    scanf("%d%d", &pedras, &sapos);

    int* array = (int*) calloc(pedras, sizeof(int));

    for(int i = 0; i < sapos; i++)
    {
        scanf("%d%d", &inicial, &distancia);
        array[inicial-1] = 1;

        checaratras(array, inicial-1, distancia);
        checarfrente(array, inicial-1, distancia, pedras);
    }

    for(int i = 0; i < pedras; i++)
    {
        printf("%d\n", array[i]);
    }

    free(array);

    return 0;
}