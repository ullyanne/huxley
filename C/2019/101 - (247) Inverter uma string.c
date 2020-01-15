#include <stdio.h>
#include <string.h>

int main()
{
    char str[256];
    int i;

    fgets(str, 256, stdin);
    
    for(i = (strlen(str) - 1); i >= 0; i--)
    {
        printf("%c", str[i]);
        
        if(i == 0)
        {
            printf("\n");
        }
    }


    return 0;
}
