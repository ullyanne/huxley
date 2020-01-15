#include <stdio.h>
#include <math.h>

int main()
{
    float C[3]; //coordenadas do usuário
    
    int cont, i;
    float aux;
    int j = 0;

    char K[] = "Kakariko";
    char S[] = "Solitude";
    char H[] = "Hogsmeade";

    float K1[3] = {0, 64, 10};
    float S1[3] = {140, 200, 456};
    float H1[3] = {34, 110, 220};

    for(i = 0; i < 3; i++)
    {
        scanf("%f", &C[i]);
    }

    float D[3];
    float k, s, h;

    D[0] = sqrt( (pow(C[0] - K1[0], 2)) + (pow(C[1] - K1[1], 2) + (pow(C[2] - K1[2], 2)) ) );
    D[1] = sqrt( (pow(C[0] - S1[0], 2)) + (pow(C[1] - S1[1], 2) + (pow(C[2] - S1[2], 2)) ) );
    D[2] = sqrt( (pow(C[0] - H1[0], 2)) + (pow(C[1] - H1[1], 2) + (pow(C[2] - H1[2], 2)) ) );
    
    k = D[0];
    s = D[1];
    h = D[2];
    
    if (s == k && k == h)
    {
        printf("%f %f %f\n", D[0], D[1], D[2]);
            
        return 0;
    }

    
    for(cont = 1; cont <= 3; cont++)
    {
        for(i = 0; i < 2; i++)
        {
            if(D[i] > D[i+1])
            {
                aux = D[i+1];
                D[i+1] = D[i];
                D[i] = aux;
            }
        }
    }

    if(s == D[0])
    {
        if(s == k)
        {
            printf("%s %s %s", S, K, H);
            return 0;
        }
        else if(s == h)
        {
            printf("%s %s %s", S, H, K);
            return 0;
        }
        else if(k == h)
        {
            printf("%s %s %s", S, K, H);
            return 0;
        }


    }
    
    if(k == D[0])
    {   
        if(k == s)
        {
            printf("%s %s %s", S, K, H);
            return 0;

        }
        else if(k == h)
        {
            printf("%s %s %s", K, H, S);
            return 0;
        }
        else if (s == h)
        {
            printf("%s %s %s", K, S, H);
            return 0;
        }

    }

    if(h == D[0])
    {
        if(h == s)
        {
            printf("%s %s %s", S, H, K);
            return 0;

        }
        else if(h == k)
        {
            printf("%s %s %s", K, H, S);
            return 0;
 
        }
        else if(k == s)
        {
            printf("%s %s %s", H, S, K);
            return 0;
        }
    }
   

    for(i = 0; i < 3; i++)
    {
        while(j < i)
        {
            printf(" ");
            j++;
        }

        if(D[i] == k)
        {
            printf("%s", K);
        }
        else if (D[i] == s)
        {
            printf("%s", S);
        }
        else if (D[i] == h)
        {
            printf("%s", H);
        }

    }
    

    return 0;
}
