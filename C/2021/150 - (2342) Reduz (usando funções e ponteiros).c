#include <stdio.h>

void reduz(float* um, float* dois)
{
    *um -= *dois;
}

int main() 
{
    float x, y;
    
    scanf("%f%f", &x, &y);
    
    reduz(&x, &y);
	
	printf("%.2f %.2f", x, y);
	return 0;
}