#include <stdio.h>
#include <math.h>

# define MAX 2000000

int				main()
{
	int			i, j, check, index = 1;
	int			list[MAX] = {0};
	long int	res;

	list[0] = 2;
	list[MAX - 1] = 1;
	for (i=3, res=2; i < MAX; i += 2)
	{
		for (check=1,j=0; list[j] <= sqrt(i); j++)
			if (!(i % list[j]))
			{
				check = 0;
				break ;
			}
		if (check)
			list[index++] = i;
		res += (check) ? i : 0;
	}
	return (printf("%ld\n", res));
}
