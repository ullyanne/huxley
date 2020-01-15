#include <stdio.h>

int main()
{
    float arvore;
    int qtenfeites[3];
    float precoenfeites[3];
    int i;

    scanf("%f", &arvore);

    float total = arvore;

    for(i = 0; i < 3; i++)
    {
        scanf("%d%f", &qtenfeites[i], &precoenfeites[i]);
        total += (qtenfeites[i]) * (precoenfeites[i]);
    }

    printf("%.2f\n%.2f\n", total, total/21);



    return 0;
}
