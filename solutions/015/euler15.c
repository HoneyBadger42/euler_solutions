#include <stdio.h>

# define SIZE 20

int				main()
{
	long int	i, res = 1;

	for (i=0; i < SIZE; i++)
		res = (res * ((2 * SIZE) - i)) / (i + 1);
	return (printf("%ld\n", res));
}
