#include <stdio.h>

int main()
{
    int l, c, i; //contadores
    int sinalizador = 0; //ajudará a quebrar um loop abaixo

    double operacoes[100][2]; //2 colunas para a operação e o valor
    
    double saldo = 0;
    double creditos = 0;
    double debitos = 0;

    for(l = 0; l < 100 && sinalizador != 1 ; l++)
    {
        for(c = 0; c < 2; c++)
        {
            scanf("%lf", &operacoes[l][c]);

            if(operacoes[l][0] == -1) //para se a operação for -1 ou se 100 operações forem lidas 
            {
                sinalizador = 1;
                break;
            }
        }
    }

    for(i = 0; i < l; i++)
    {
        if(operacoes[i][0])
        {
            creditos += operacoes[i][1];
            saldo += operacoes[i][1];
        }
        else if( !operacoes[i][0])
        {
            debitos += operacoes[i][1];
            saldo -= operacoes[i][1];
        }
        
    }

    printf("Creditos: R$ %.2lf\nDebitos: R$ %.2lf\nSaldo: R$ %.2lf\n", creditos, debitos, saldo);

    return 0;
}
