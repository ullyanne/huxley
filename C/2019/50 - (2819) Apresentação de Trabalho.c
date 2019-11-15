#include <stdio.h>

int main()
{
	int ig, ia, en, ind, str;

	scanf("%d%d%d%d%d", &ig, &ia, &en, &ind, &str);

	if (ig == 1 || ia == 1)
	{
		if (en == 1 && ind == 1)
		{
			if(str == 1)
			{
				printf("Trabalho aborda Interface Grafica? (0 - Nao 1 - Sim)\nTrabalho aborda Inteligencia Artificial? (0 - Nao 1 - Sim)\nTrabalho aborda Encapsulamento? (0 - Nao 1 - Sim)\nTrabalho aborda Indentacao? (0 - Nao 1 - Sim)\nTrabalho aborda Structs? (0 - Nao 1 - Sim)\nSeu trabalho sera avaliado.\n");
			}
			else
			{
			printf("Trabalho aborda Interface Grafica? (0 - Nao 1 - Sim)\nTrabalho aborda Inteligencia Artificial? (0 - Nao 1 - Sim)\nTrabalho aborda Encapsulamento? (0 - Nao 1 - Sim)\nTrabalho aborda Indentacao? (0 - Nao 1 - Sim)\nTrabalho aborda Structs? (0 - Nao 1 - Sim)\nSeu trabalho nao sera avaliado, nota 0.\n");
			}
		}
		else
		{
			printf("Trabalho aborda Interface Grafica? (0 - Nao 1 - Sim)\nTrabalho aborda Inteligencia Artificial? (0 - Nao 1 - Sim)\nTrabalho aborda Encapsulamento? (0 - Nao 1 - Sim)\nTrabalho aborda Indentacao? (0 - Nao 1 - Sim)\nTrabalho aborda Structs? (0 - Nao 1 - Sim)\nSeu trabalho nao sera avaliado, nota 0.\n");
		}

	}
	else 
	{
		printf("Trabalho aborda Interface Grafica? (0 - Nao 1 - Sim)\nTrabalho aborda Inteligencia Artificial? (0 - Nao 1 - Sim)\nTrabalho aborda Encapsulamento? (0 - Nao 1 - Sim)\nTrabalho aborda Indentacao? (0 - Nao 1 - Sim)\nTrabalho aborda Structs? (0 - Nao 1 - Sim)\nSeu trabalho nao sera avaliado, nota 0.");
	}

	return 0;
}
