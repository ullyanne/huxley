#include <stdio.h>
#include <math.h>

int rodadasbeza(int v1, int d2)
{
    int rodadas;

    if(v1 <= d2) //instakill
    {
        return 1;
    }

    rodadas = ceil(v1/(float) d2);

    return rodadas;

}

int rodadasclo(int v2, int d1)
{
    int rodadas;

    if(v2 <= d1) //instakill
    {
        return 1;
    }

    rodadas = ceil(v2/(float) d1);

    return rodadas;
}

void batalha(int v1, int v2, int d1, int d2)
{   
    int gameover = 0;
    int r = rodadasclo(v2, d1);


    while(gameover == 0)
    {              
        r = rodadasclo(v2, d1);
        rodadasbeza(v1, d2);

        if(r > rodadasbeza(v1, d2) )
        {
            d1+= 50;
   
            v1 = v1 - d2;
            
                if(v1 <= 0)
                {
                    printf("Bezaliel\n");
                    gameover = 1;
                }

        }
        else
        {
            v2 = v2 - d1;

            if(v2 <= 0)
            {
                printf("Clodes\n");
                gameover = 1;
            }
            else
            {
                v1 = (v1 - d2);

                if(v1 <= 0)
                {
                    printf("Bezaliel\n");
                    gameover = 1;

                }

            }
            
 

        }
    }
}

int main()
{
    int v1, v2, d1, d2;
    int n, i;

    scanf("%d", &n);
  
    for(i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &v1, &v2, &d1, &d2);

        if( rodadasclo(v2, d1) <= rodadasbeza(v1, d2) )
        {
            printf("Clodes\n");
        }
        else
        {                       
            batalha(v1, v2, d1, d2);
        }
    }

    return 0;
}
