#include <stdio.h>
#include <math.h>

int primo(int x)
{
    int i;

    if(x == 2)
    {
        return 1;
    }
        
    for(i = 2; i < (x-1); i++)
    {
        if(x%i == 0)
        {
            return 0;
        }
    }

    return 1;
 
}


int mmc(int x, int y)
{
    int maiornumero; //para criar arrays com quantidade igual ao maior numero

    maiornumero = x;

    if(y > x)
    {
        maiornumero = y;
    }

    int fat [maiornumero]; //tamanho n, porque é indeterminado, aleatório
    int pot [maiornumero];
    int fat2 [maiornumero]; 
    int pot2 [maiornumero];


    int i, maiorposicao, maiorfat, maiorpot; //mmc pega o maior fator e a maior potencia
    int j = 0; //contador de posicoes
    int k = 0; //contador de posicoes
    
    int r = 1; //resultado do mmc
  
  
  
    //preenchendo tudo com zeros

    for(i = 0; i < maiornumero; i++)
    {
        fat[i] = 0;
        fat2[i] = 0;
        pot[i] = 0;
        pot2[i] = 0;
    }

    //



    for(i = 2; x != 1; i++)
    {
        if( primo (i) ) //imprimir todos os primos até n = 1
        {   
            fat[j] = i;
            pot[j] = 0; //potência começa em 0
            

            while ( x % i == 0)
            {
                pot[j] += 1;
                x = (x/i);
            }
            
            j++; //aumentar a posição
        }
    }

    for(i = 2; y != 1; i++)
    {   

        if( primo (i) ) //imprimir todos os primos até n = 1
        {   
            fat2[k] = i;
            pot2[k] = 0; //potência começa em 0
            
            while( y % i == 0)
            {
                pot2[k] += 1;
                y = (y/i);
            }
            
            k++; //aumentar a posição
        }
    }

    maiorposicao = j;

    if(k > j)
    {
        maiorposicao = k;
    }

    for(i= 0; i < maiorposicao; i++)
    {
       //------------*
       
        maiorfat = fat[i];

        if(fat2[i] > fat[i])
        {
            maiorfat = fat2[i];
        }

        //----------*

        maiorpot = pot[i];

        if(pot2[i] > pot[i])
        {
            maiorpot = pot2[i];
        }

        //-----------*

        r *= pow(maiorfat, maiorpot);
        
        
  
    }

    return r;
    
}

int main()
{
    int n, n2; //dois numeros inseridos pelo usuario
    int i = 1; //auxiliar para contar múltiplos, vai ser multiplicado pelo mmc
    int j; //quantidade de numeros multiplos do mmc que sao menores que 50
    int r; //mmc

    scanf("%d", &n);
    scanf("%d", &n2);

    r = mmc(n, n2);

    int multiplos = r * i; //multiplos do mmc

    for(i = 1, j = 0; multiplos < 50; i++)
    {
        multiplos = r * i; 

        if(multiplos < 50)
        {
            j++;
        }

    }

    printf("%d\n", j); 


    return 0;
}
