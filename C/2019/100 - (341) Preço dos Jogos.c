#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    int dificuldade[n];
    double precosatuais[n];
    double precosfuturos[n];

    for(i = 0; i < n; i++)
    {   
        scanf("%d%lf", &dificuldade[i], &precosatuais[i]);

        for(j = 0; j < 3; j++)
        {
            if(precosatuais[i] > 45)
            {
      
                if(dificuldade[i] == 0)
                {
                    if(precosatuais[i] <= 100)
                    {
                        precosfuturos[i] = (precosatuais[i] - (precosatuais[i] * (0.25/2)));
                    }
                    else
                    {
                        precosfuturos[i] = precosatuais[i] - (precosatuais[i] * 0.25);
                    }

                }
                else if(dificuldade[i] == 1)
                {   
                    if(precosatuais[i] <= 100)
                    {
            
                        precosfuturos[i] = (precosatuais[i] - (precosatuais[i] * (0.2/2)));
        
                    }
                    else 
                    {
                        precosfuturos[i] = precosatuais[i] - (precosatuais[i] * 0.2);
                    }

                }
                else if(dificuldade[i] == 2)
                {   
                    if(precosatuais[i] <= 100)
                    {
                        precosfuturos[i] = (precosatuais[i] - (precosatuais[i] * (0.18/2)));
                    }
                    else
                    {
                        precosfuturos[i] = precosatuais[i] - (precosatuais[i] * 0.18);
                    }

                }
                else if(dificuldade[i] == 3)
                {
                    if(precosatuais[i] <= 100)
                    {
                        precosfuturos[i] = (precosatuais[i] - (precosatuais[i] * (0.15/2)));
                    }
                    else
                    {
                        precosfuturos[i] = precosatuais[i] - (precosatuais[i] * 0.15);
                    }

                }
                else if(dificuldade[i] == 4)
                {
                
                    if(precosatuais[i] <= 100)
                    {
                        precosfuturos[i] = (precosatuais[i] - (precosatuais[i] * (0.12/2)));
                    }
                    else
                    {
                        precosfuturos[i] = precosatuais[i] - (precosatuais[i] * 0.12);
                    }

                }
                else if(dificuldade[i] == 5)
                {
                    if(precosatuais[i] <= 100)
                    {
                        precosfuturos[i] = (precosatuais[i] - (precosatuais[i] * (0.1/2)));
                    }
                    else
                    {
                        precosfuturos[i] = precosatuais[i] - (precosatuais[i] * 0.1);
                    }

                }

                if(precosfuturos[i] < 45)
                {
                    precosfuturos[i] = 45;
                }

                precosatuais[i] = precosfuturos[i];


            }
 
        }//final do forj
    
        printf("Jogo[%d] = R$%.2lf\n", i, precosatuais[i]);
    
    
    }


    return 0;
}
