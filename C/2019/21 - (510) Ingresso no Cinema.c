#include <stdio.h>

int main()
{
	int est, id;

	scanf("%d%d", &est, &id);

	if(est == 0)
	{
		if (id == 1)
		{
			printf("1");
		}

		else 
		{
			printf("0");
		}
	}

	else if (est == 1)
	{
		printf("1");
	}


	return 0;
}
