#include <stdio.h>
#include <stdlib.h>

// real	0m0.382s
// user	0m0.276s
// sys	0m0.104s
// 99% CPU

long int		mod = 1475789056;

long int		ack(int val, int mod)
{
	long int	i, nMod, ret, tmp = 1;
	long int	*niz = (long int *)malloc(sizeof(long int) * 25000000);

	if (val == 1)
		return (2);
	for (i=1; i <= 25000000; i++)
	{
		if ((tmp = (tmp * 2) % mod) < 25000000 && niz[tmp])
		{
			nMod = i - niz[tmp];
			break;
		}
		if (tmp < 25000000)
			niz[tmp] = i;
	}
	ret = ack(val - 1, nMod);
	for (i=1, tmp=1; i <= ret; i++)
		tmp = (tmp * 2) % mod;
	return (tmp);
}

int				main()
{
	int			srcAck = 1 + 3 + 7 + 61;

	printf("%ld\n", (ack(7, mod) + 2 * ack(10, mod) - (3 * 3) + srcAck) % mod);
	return 0;
}
