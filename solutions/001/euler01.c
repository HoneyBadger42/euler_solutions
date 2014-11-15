#include <stdio.h>

int	main()
{
	int	i,j;
	for (i=1,j=0; i < 1000; i++)
		j += (i%3) ? (i%5) ? 0 : i : i;
	return (printf("%d\n", j));
}
