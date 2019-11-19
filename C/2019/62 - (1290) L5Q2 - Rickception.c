#include <stdio.h>

int ricky_morty (int n, int t, int c)
{
	if (c == t)
	{
		return n;
	}
		
		else if (c % 2 != 0)
		{
			n += (n%5);

			return ricky_morty(n, t, c+1);
		} 
			else 
			{
				n+= 3;

				return ricky_morty(n, t, c+1);
			}
}

int main()
{
	int n, t, resp;

	scanf("%d%d", &n, &t);

	resp = ricky_morty(n, t, 0);

	printf("%d\n", resp);
	
	return 0;
}
