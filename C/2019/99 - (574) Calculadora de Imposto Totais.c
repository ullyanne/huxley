#include <stdio.h>

int main()
{
    //----------------------R$*

    double produto, frete;
    double cotacao, aliquota;
    double totaldeverdade;

    scanf("%lf%lf%lf%lf", &cotacao, &aliquota, &produto, &frete);

    aliquota = aliquota/100;
    
    //-----------------------US$*

    double produto2, frete2, valortotal; 
    double valorfinal, icms, importacao, totalimpostos; //impostos

    produto2 = cotacao * produto;
    frete2 = cotacao * frete;
        valortotal = produto2 + frete2;

    if(produto >= 2500)
    {
        importacao = 0.6 * produto2;

        valorfinal = (produto2 + importacao)/(1- aliquota); 

        icms = valorfinal * aliquota;
            totalimpostos = icms + importacao;

        totaldeverdade = totalimpostos + valortotal;

        printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\nImpostos calculados sem o frete\n", cotacao, produto2, frete2, valortotal, importacao, icms, totalimpostos, totaldeverdade);

    }    
    else //frete incluso nos impostos
    {
        importacao = 0.6 * valortotal;

        valorfinal = (produto2 + frete2 + importacao)/(1 - aliquota);

        icms = valorfinal * aliquota;
            totalimpostos = icms + importacao;

        totaldeverdade = totalimpostos + valortotal;

        printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\nImpostos calculados com o frete\n", cotacao, produto2, frete2, valortotal, importacao, icms, totalimpostos, totaldeverdade);

    }

  


    return 0;
}
