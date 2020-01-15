#include <stdio.h>

int funcpar(int x)
{
    x = (x/2);

    return x;
}

int funcimpar(int x)
{
    x = (x * 3) + 1;

    return x;
}


int main()
{
    int i, j; //entradas do usuario, intervalo
   
    int novoi, novoj; //entradas do usuario que sao utilizadas nas operacoes

    int u, k, aux; //contadores e auxiliares
    int intervalo, tam; //tam e' o tamanho do ciclo
    int n;

    int maior;

    while(scanf("%d%d", &i, &j) != EOF)
    {   
        novoi = i;
        novoj = j;

        if(novoi > novoj)
        {
            aux = novoi;
            novoi = novoj;
            novoj = aux;
        }

       
        intervalo = (novoj - novoi) +1; //quantidade de numeros entre i e j, incluindo ambos
        
        int A[intervalo]; //array para guardar a qt de ciclos de cada numero do intervalo
       
        n = 0; //contador de posicoes do array

        maior = 0; //servirá para comparar a maior posicao de arrays
        


        for(k = novoi; k<= novoj; k++ ) //for para passar em cada numero do intervalo
        {
            tam = 1; //tamanho minimo dos ciclos, ele ja conta com o 1 final

            if(k == 1) //se o primeiro numero for 1, qt de ciclos = 1
            {
                A[n] = tam;

                if(A[n] > maior)
                {
                    maior = A[n];
                }
               
                n++;
            }
            else
            {   
                u = k; //variavel auxiliar

                while(u != 1) //fazer esse processo ate u = 1
                {
                    if(u%2 == 0)
                    {
                        u = funcpar(u);

                        tam++; //se precisou fazer alguma operacao, o numero de ciclos aumenta
                    }
                    else //se u for impar
                    {  
                        u = funcimpar(u);

                        tam++;
                    }
                    
                }

                A[n] = tam; //array que guarda o numero de ciclos, tam = numero de ciclos

                if(A[n] > maior)
                {
                    maior = A[n];
                }

                n++;

            }
                
 
            
        } //final do for grandao


            printf("%d %d %d\n", i, j, maior);


    } //final do while



    return 0;
}
