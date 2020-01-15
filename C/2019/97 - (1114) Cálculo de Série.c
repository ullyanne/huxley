#include <stdio.h>
#include <math.h>

int multtres(int y) //função que retorna o próximo múltiplo de três
{
    y = y + 3;

    return y;
}

int potencia(int expoente) //função que muda o expoente de um número com base 2, retorna o valor desse número
{
    expoente = expoente+1; 
    
    int num = pow(2, expoente);

    return num; 
}


int impar(int x) //função que retorna o próximo ímpar
{
    x = x + 2;

    return x;
}

int main()
{
    double numimpar = -1; //-1 porque o próximo será 1 (primeiro termo da sequência)

    double multiplotres = 0; //0 porque o próximo múltiplo será 3 (0 + 3 = 3) (3 + 3 = 6)

    int expoente = -1; //-1 porque o primeiro número será elevado a 0 (expoente++) -> 2^0, 2^1 etc.
    int pot; //o número, não apenas o expoente. valor de 2^0, 2^1 etc. 
   
    double soma = 0; //como vai ser dividido, está em double ele e +2 variáveis
    
    int i, n; //contador e número fornecido pelo usuário. n = an da sequência

    scanf("%d", &n);


    for(i = 1; i <= n; i++)
    {
        if(i % 2 != 0) //se o n termo da sequência for ímpar
        {   
            numimpar = impar(numimpar); //se transforma no próximo número ímpar (-1 + 2 = 1)
 
            pot = potencia(expoente); //se transforma na proxima potencia (-1 + 1 = 0) (0 + 1 = 1) -> 2^0 e 2^1
            expoente++;

            soma += (numimpar/pot); //padrão 
  
        }
        else
        {
            pot = potencia(expoente);
            expoente++;


            multiplotres = multtres(multiplotres); //se transforma no próximo múltiplo de 3 

            soma += (pot/multiplotres); //padrão
        }
    }

    printf("S: %.2lf\n", soma); //soma total, depois de n somas


    return 0;
}
