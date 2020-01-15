#include <stdio.h>

int main()
{
    float precovelho[5];
    float preconovo[5];
    float desconto[5];
    int i;
    int cont = 0;
    
    for(i = 0; i < 5; i++)
    {
        scanf("%f%f", &precovelho[i], &preconovo[i]);
        
        desconto[i] =  preconovo[i]/precovelho[i];
      
        if(desconto[i] <= 0.8f) //f � uma convers�o de 0.8 (double) para float
        {
            cont++;
        }

    }

    printf("%d\n", cont);

    return 0;
}
