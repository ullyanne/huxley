#include <stdio.h>

int validade(int matriz[3][3])
{
    int valido = 1; //válido (1) até provar o contrário 
    int i, j;

    //---diagonal principal

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(i != j)
            {
                if(matriz[i][j] != 0)
                {
                    valido = 0;
                    i = 3;
                    break;
                }
            }
            else if(i == j)
            {
                if(matriz[i][j] != 1)
                {
                    valido = 0;
                    i = 3;
                    break;
                }
            }
        }
    }

    //---diagonal secundária
    
    if(!valido)
    {   
        valido = -1; //a diag. secundária é válida (-1) até provar o contrário


        //essas abaixos fazem parte da diagonal secundária, e, para a matriz ser válida, elas têm que ser iguais a 1
        if(matriz[0][2] != 1) 
        {
            valido = 0;
            return valido;
        }
        else if(matriz[1][1] != 1)
        {
            valido = 0;
            return valido;
        }
        else if(matriz[2][0] != 1)
        {
            valido = 0;
            return valido;
        }

    //para checar se os números que não fazem parte da diagonal secundária são iguais a 0
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(i == 0)
                {   
                    if(j != 2) // excluindo [0][2] porque faz parte da diagonal secundária
                    {
                        if(matriz[i][j] != 0)
                        {         
                            valido = 0;
                            return valido;
                        }
                    }
    
                }
                else if(i == 1)
                {                
                    if(j!= 1) //excluindo [1][1] porque faz parte da diagonal secundária
                    {
                        if(matriz[i][j] != 0)
                        {           
                            valido = 0;
                            return valido;
                        }
                    }

                }
                else if(i == 2)
                {    
                    if(j != 0) //excluindo [2][0] porque faz parte da diagonal secundária
                    {
                        if(matriz[i][j] != 0)
                        {                  
                            valido = 0;
                            return valido;
                        }
                    }
                }
            
            }
        }

    }
    
    return valido;
}

int main()
{
    int luke[3][3];
    int vidaluke;
    int lukegolpes[10]; //a validez de cada matriz ficará guardada aqui. no máximo são 10 golpes (matrizes)

    int vader[3][3];
    int vidavader;
    int vadergolpes[10];

    int cont = 0;
    int l = 0;
    int c = 0;
 
    scanf("%d%d", &vidaluke, &vidavader);

    while(cont != 10 && scanf("%d", &luke[l][c]) != EOF) 
    //requisito de parada: até 10 rodadas (golpes) por cada atacante ou EOF
    //cont != 10 primeiro, pois se estivesse ao contrário e 10 fosse atingido pelo cont...
    //mas ainda tivesse linhas para ler, seria armazenado um valor até chegar na parte do cont != 10
    {   
        for(l = 0; l < 3; l++)
        {
            for(c = 0; c < 3; c++)
            {   
                if(c == 0 && l == 0) 
                //como [0][0] vai ser lido no while, faz-se necessário mudar apenas a posição do primeiro número lido nesse loop
                {
                    c = 1;
                }
                
                scanf("%d", &luke[l][c]);
            }
        }   
        
        lukegolpes[cont] = validade(luke); //1 -> diag. principal válida; -1 -> diag. secundária válida; 0 -> matriz inválida
        
        for(l = 0; l < 3; l++)
        {   
            for(c = 0; c < 3; c++)
            {   
                scanf("%d", &vader[l][c]);
            }
        }

        vadergolpes[cont] = validade(vader);

        l = 0; //resetando as posições, isso é feito no for, mas o while também tem scanf
        c = 0;
        cont++;
    }


    for(l = 0; l < cont; l++)
    {   
        if(!lukegolpes[l]) //se a matriz for inválida
        {
            if(vadergolpes[l] == 1 || vadergolpes[l] == -1) //só levará dano se a matriz do oponente for válida
            {
                vidaluke -= 15;
            }
        }
            
        else if(lukegolpes[l]) //se a matriz for válida (1)
        {
            if(!vadergolpes[l]) //o oponente tomará dano se a matriz dele for inválida (0)
            {
                vidavader -= 15;
            }
            else if(vadergolpes[l]) //se a matriz do oponente também for válida (1), os dois levam dano
            {
                vidavader -= 15;
                vidaluke -= 15;
            } 
            
            //caso contrário, ninguém tomará dano
        }
        
        else if(lukegolpes[l] == -1)
        {
            if(!vadergolpes[l])
            {
                vidavader -= 15;
            }
            else if(vadergolpes[l] == -1)
            {
                vidavader -= 15;
                vidaluke -= 15;
            }
        }
    }

    if(vidaluke == vidavader)
    {
        printf("Houve empate.\n");
    }
    else if(vidavader > vidaluke)
    {
        printf("Darth Vader venceu.\n");
    }
    else if(vidaluke > vidavader)
    {
        printf("Luke Skywalker venceu.\n");
    }

    return 0;
}
