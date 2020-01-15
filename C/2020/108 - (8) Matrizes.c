#include <stdio.h>

int main()
{
    int n, m; //n = linha, m = coluna
    int lin, col;
    
    float cont;
    
    float celulas[1000][1000];

    float auxlinha, auxcoluna; 
    //servem para delimitar a diagonal esquerda, começam com as coordenadas da última celula da matriz

    float t; //soma de todas as células
    float x; //soma da diagonal direita
    float y; //soma da diagonal esquerda 
    float a; //soma de valores da primeira coluna
    float b; //soma de valores da última coluna
    float c; //soma de valores da primeira linha
    float d; //soma de valores da última linha
    float resposta;

    while(scanf("%d%d", &n, &m) && (n!=0 || m != 0))
    {   
        cont = 1;
        t = 0;
        x = 0;
        y = 0;
        a = 0;
        b = 0;
        c = 0;
        d = 0;

        auxlinha = n - 1;
        auxcoluna = m - 1; //coordenadas da última célula
        
        while(auxlinha != 0 && auxcoluna != 0) 
        //modifica os aux para serem iguais às coordenadas da primeira célula da diagonal esquerda
        {   
            auxlinha--;
            auxcoluna--;
        }

        for(lin = 0; lin < n; lin++)
        {
            for(col = 0; col < m; col++)
            {
                celulas[lin][col] = cont;
                cont++;

                t += celulas[lin][col]; //t

                if(lin == col) //x
                {
                    x += celulas[lin][col];
                }

                if(lin == auxlinha && col == auxcoluna) //y
                {
                    y += celulas[lin][col];
        
                    auxlinha++;
                    auxcoluna++;
                }
                
                if(col == 0) //a
                {
                    a += celulas[lin][col];
                }

                if(col == m -1) //b
                {
                    b += celulas[lin][col];
                }

                if(lin == 0) //c
                {
                    c += celulas[lin][col];
                }

                if(lin == n-1) //d
                {
                    d += celulas[lin][col];
                }

            } //for de coluna

        
        } //for de linha

        // printf("%d %d %d %d %d %d %d\n", t, x, a, b, c, d, y);
        if(n == 0 || m == 0)
        {
            resposta = 0;
        }
        else
        {
            resposta = (t - (x + y) + (a * b) - (c * d))/(n * m);
        }
        
        printf("%.2f\n", resposta);
    }


    return 0;
}
