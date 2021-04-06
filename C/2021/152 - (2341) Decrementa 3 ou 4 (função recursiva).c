#include <stdio.h>

int primeirodigito(int num)
{
    if(num >= 10)
    {
        return primeirodigito(num/10);
    }
    return num;
}

int main()
{
    int num;

    scanf("%d", &num);

    primeirodigito(num)%2 == 0? printf("%d\n", num-4): printf("%d\n", num-3);
    return 0;
}