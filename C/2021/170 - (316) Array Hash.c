#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(int key)
{
    return key%65;
}

int main()
{

    int cases, lines, total;
    char str[50];
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {   
        total = 0;
        
        scanf("%d", &lines);

        for(int j = 0; j < lines; j++)
        {
            scanf("%s", str);
            
            for(int k = 0; k < strlen(str); k++)
            {
                total+= j + k + hash((int)str[k]);
            }
        }

        printf("%d\n", total);
    }

    return 0;
}


