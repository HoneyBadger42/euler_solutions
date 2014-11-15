#include <stdio.h>

int			isPrime(int x)
{
	int		i;

	if (x < 2)
		return (0);
	for (i=2; i*i <= x; i++)
		if (!(x%i))
			return (0);
	return (1);
}

int			main(void)
{
	int		i, j=1;

	for (i=0; 1; i++)
		if (isPrime(i))
			if (j++ == 10001)
				break ;
	return (printf("%d\n", i));
}
