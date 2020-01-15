#include <stdio.h>
#include <string.h>

int main()
{
    int i, j; //contadores

    char str[1000]; //string não invertida
    char str2[1000];
    char newstr[1000] = ""; //string invertida e preenchida com null
    char newstr2[1000] = "";

    char resultado[1000] = ""; //string não invertida e preenchida com null
    char newresultado[1000] = ""; //string invertida e preenchida com null

    scanf("%s %s", str, str2);

    //invertendo as strings para facilitar na hora da soma, por conta da posição de cada char

    for(i = strlen(str)-1, j = 0; i >= 0; i--, j++)
    //i = último caractere válido sem ser o null
    //j = contador para formar a nova string
    {
        newstr[j] = str[i];
    }

    for(i = strlen(str2)-1, j = 0; i >= 0; i--, j++)
    {
        newstr2[j] = str2[i];
    }

    int maiorlen = strlen(str);
    int menorlen = strlen(str2);

    if(menorlen > maiorlen)
    {
        maiorlen = strlen(str2);
        menorlen = strlen(str);
    }

    int carry = 0; //carry = 1 quando o número resultante for maior que 10
    int soma;

    for(i = 0; i < menorlen ; i++) //soma a menor com a maior string, até acabar os caracteres válidos da menor string
    {
        soma = (newstr[i] - '0') + (newstr2[i] - '0') + carry; 
        //char - char -> valor ascii - valor ascii
        //o 0 fica em cima de todos os números, então a diferença será mantida
        //transformou de char pra int

        resultado[i] = soma % 10 + '0'; 
        //voltou pra char
        
        carry = soma/10; //excessos
    }


    for(i = menorlen; i < maiorlen; i++) //agora que percorreu até a menor string, tem que somar a maior string com carries, caso haja
    {   
        if(menorlen == strlen(str)) //maior seria str2
        {
            soma = (newstr2[i] - '0') + carry;
        }
        else //maior seria str
        {
            soma = (newstr[i] - '0') + carry;
        }

        resultado[i] = soma % 10 + '0';

        carry = soma/10;    
    }

    if(carry) 
    //caso o tamanho das duas strings seja o mesmo, sobrarão carries
    //além disso, mesmo percorrendo até a maior string, poderão sobrar carries para serem somados
    {  
        resultado[maiorlen] = 1 + '0';
    }
 
    //invertendo a string de resultado
    for(i = strlen(resultado)-1, j = 0; i >= 0; i--, j++)
    {
        newresultado[j] = resultado[i];
    }

    puts(newresultado);
    
    return 0;
}
