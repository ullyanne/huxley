#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    char str[n+1];
    int num;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        scanf(" %c", &str[num-1]);
    }

    str[n] = '\0';

    printf("%s", str);

    return 0;
}