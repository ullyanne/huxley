#include <stdio.h>
#include <math.h>

int fatorial(int z)
{
    int i;

    if (z == 1)
    {
        return 1;
    }
    else
    {
        return (z * fatorial(z-1)); 
    }
}

int primo(int x)
{   
    double a = sqrt(x);
    int i;

    if(x == 2 || x == 1) //�, a quest�o classificou 1 como sendo primo
    {
        return 1;
    }

    for(i = 2; i < a+1; i++)
    {
        if(x%i == 0)
        {
            return 0;
        }
    }

    return 1;

}

int proxprimo(int y)
{
    int i;

    for(i = 1;  ; i++)
    {
        if(primo(y+i)) 
        {
            return (y+i);
        }
    }
}


int main()
{
    int i, n;
    int j = 1;

    scanf("%d", &n);

    int P[n];
    double soma = 0;
    
    if(n <= 0)
    {
        printf("%.2lf\n", soma);

        return 0;
    }

    for(i = 1; i <= n; i++)
    {

        if( primo(i))
        {
            soma += (fatorial(i))/ (double)i;
            P[i-2] = i; //dividendo
           
        }
        else
        {
            soma += (fatorial(i))/ (double)proxprimo(i);
            P[i-2] = proxprimo(i); //dividendo
        }

        //resultados
        
         while(j < i)
        {
            printf(" + ");
            j++;
        }

        printf("%d!/%d", i, P[i-2]);
        

    }

    printf("\n%.2lf\n", soma);


    return 0;
}
