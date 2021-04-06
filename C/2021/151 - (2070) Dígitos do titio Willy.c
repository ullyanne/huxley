#include <stdio.h>
#include <string.h>

int algdigitos(int (*function)(int), char *array, int len, int *total)
{
    if (len > 0)
    {
        int num = *array - '0';

        if (function(num))
        {
            *total += num * len * 2;
        }
        else
        {
            *total += num * len * 3;
        }
        return algdigitos(function, array + 1, len - 1, total);
    }
}

int paridade(int num)
{
    return num % 2 == 0 ? 1 : 0;
}

int main()
{
    char dig[10];

    while(scanf("%s", dig) && dig[0]- '0' != 0)
    {
        int len = strlen(dig);
        int total = 0;

        algdigitos(paridade, dig, len, &total);
        printf("%d\n", total);
    }
    return 0;
}