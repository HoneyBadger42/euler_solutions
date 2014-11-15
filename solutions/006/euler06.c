#include <stdio.h>

int			main()
{
	int		i, sum1, sum2;

	for (i=1, sum1=0; i <= 100; i++)
		sum1 += i*i;
	for (i=1, sum2=0; i <= 100; i++)
		sum2 += i;
	return (printf("%d\n", ((sum2 * sum2) - sum1)));
}
