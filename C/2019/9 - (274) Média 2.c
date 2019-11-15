#include <stdio.h>

int main()

{
	int i = 0;
	float notas[3], media;
	char a[] = "MEDIA = "; 

	while(i < 3)
	{
		scanf("%f", &notas[i]);
		i++;
	}

	media = (2*(notas[0]) + 3*(notas[1]) + 5*(notas[2]))/(2+3+5);

	printf("%s%.1f", a, media);


	return 0;
}
