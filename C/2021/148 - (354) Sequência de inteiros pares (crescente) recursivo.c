#include <stdio.h>

void par(int n)
{
    if(n >= 0 ) 
    //condição de parada, para não ir até os negativos
    {
        if(n%2 == 0)
        //checar se é par
        {
            par(n-1);
            printf("%d\n", n);
        }
        else
        //caso não seja, seguir em frente e ir para o próximo número
        {
            par(n-1);
        }
    }
    
}

int main() {
	
	int n;
	
	scanf("%d", &n);
	
	par(n);
	return 0;
}