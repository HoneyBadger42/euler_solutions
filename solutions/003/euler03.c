#include <stdio.h>

int			main()
{
	int		res, tmp, start;
	long	max = 600851475143;

	for (res=0,start=2,tmp=start; tmp <= max; tmp++)
		if(!(max % tmp))
		{
			max /= tmp;
			res = (res < tmp) ? tmp : res;
			tmp = start;
		}
	return (printf("%d\n", res));
}
