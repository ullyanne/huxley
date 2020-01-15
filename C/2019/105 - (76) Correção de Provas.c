#include <stdio.h>
#include <string.h>

int maiorvalor(float freqnotas[], int l)
{
    float maior = freqnotas[0]; //maior valor
    int posicaodomaior = 0; //posicao do maior valor

    int i;

    for(i = 0; i < l; i++)
    {
        if(freqnotas[i] > maior)
        {
            maior = freqnotas[i];
            posicaodomaior = i;
        }
    }

    return posicaodomaior; 
}


float freq_notas(float notas[], int l)
{
    float freqnotas[l]; //contador de frequências

    int j, i;
    
    for(j = 0; j < l; j++) //vai analisar cada nota do array
    {   
        freqnotas[j] = 0;

        for(i = 0; i < l; i++) //muda as notas comparadas, compara com a nota i = 2, i = 3 etc.
        {
            if(notas[j] == notas[i]) 
            {
                freqnotas[j]++;
            }
        }
    }

    return notas[maiorvalor(freqnotas, l)]; 
    
    //retorna a nota de maior frequencia
    //colocou na função de maior valor para saber qual é a maior frequência, mas ela retorna a posição da maior frequência
    //para assim retornar a posição certa em "notas"
}

double percentual(float totalaprovados, int totalalunos)
{
    double aprovados = (totalaprovados/totalalunos) * 100;

    return aprovados;
}

int main()
{
    char gabarito[11];
    
    fgets(gabarito, 11, stdin); //gabarito, 10 caracteres utilizáveis
    
    
    int l, c;

    int alunos[100]; //cada aluno listado (primeiro, segundo etc.)
    float notas[100] = {0}; //nota de cada aluno, começa em 0, depois aumenta. cada questão vale 1.00
    float aprovados = 0;

    char resps[100][11]; 
    //array de arrays (strings), 100 porque é um número aleatório, grande 
    //11 porque é o máximo de colunas (corresponde à resposta)

    for(l = 0 ; scanf("%d", &alunos[l]) && alunos[l] != 9999 ; l++) //cada aluno listado, para quando o aluno listado for 9999
    {  
        printf("%d ", alunos[l]);

        for(c = 0; c < 10; c++) //respostas do aluno, 10 caracteres utilizáveis (0 - 9)
        {
            scanf(" %c", &resps[l][c]); //a quantidade de linhas é igual à ordem do aluno listado (qt de alunos = l)
            
            if(resps[l][c] == gabarito[c]) //comparando cada resposta do aluno com as do gabarito
            {
                notas[l]++;
            }

        }

        resps[l][10] = '\0'; //preencheu o último com caractere nulo

        if(notas[l] >= 6) //qt de aprovados
        {
            aprovados++;
        }

        printf("%.1f\n", notas[l]);

    }

    printf("%.1lf%%\n%.1f\n", percentual(aprovados, l), freq_notas(notas, l));

    return 0;
}
