#include <stdio.h>
#include <math.h>

int main()
{
	double raio, area_esfera, volume_esfera, pi;

	scanf("%lf", &raio);

	pi = 3.1416;
	area_esfera = 4 * pi * pow(raio, 2);
	volume_esfera = ( 4 * pi * (pow (raio, 3)) ) / 3;

	printf("%.2lf\n%.2lf\n", area_esfera, volume_esfera );



	return 0;
}
