#include <stdio.h>

int main()
{
	float l, va, vg, vd, valor;
	char t;

		scanf("%f %c", &l, &t);

		va = (l * 1.9);
		vg = (l * 2.5);
		vd = (l * 1.66);

		if (t == 'A')
		{
			if(l <= 20)
			{
				valor = va - (0.03 * va);
				printf("R$ %.2f\n", valor);
			}

			else
			{
				valor = va - (0.05 * va);
				printf("R$ %.2f\n", valor);
			}

		}

		if (t == 'G')
		{
			if(l <= 20)
			{
				valor = vg - (0.04 * vg);
				printf("R$ %.2f\n", valor);
			}

			else
			{
				valor = vg - (0.06 * vg);
				printf("R$ %.2f\n", valor);
			}

		}

		if (t == 'D')
		{
			if(l > 25)
			{
				valor = vd - (0.04 * vd);
				printf("R$ %.2f\n", valor);
			}

			else
			{
				valor = vd;
				printf("R$ %.2f\n", valor);
			}
		}





	return 0;
}
