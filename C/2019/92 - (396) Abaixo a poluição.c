#include <stdio.h>

int main()
{
    int A[100];
    int casasmultadas = 0;
    float multas = 0; 
    int n;
    
    for(n = 0; ; n++)
    {
        scanf("%d", &A[n]);

        if(A[n] > 2 && A[n] != 999)
        {
            multas+= (A[n] - 2) * 12.89;
            
            casasmultadas++;
        }

        if(A[n] == 999)
        {
            break;
        }

    }

    printf("%.2f\n%d\n", multas, casasmultadas);


    return 0;
}
