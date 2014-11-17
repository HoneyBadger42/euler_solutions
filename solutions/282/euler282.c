#include <stdio.h>
#include <stdlib.h>

using namespace std;

long int		mod = 1475789056;

long int		ack(int val, int mod)
{
	long int	m = 1, pom, ret, i;
	long int	*niz = (long int *)malloc(sizeof(long int) * 25000000);

	if (val == 1)
		return (2);
	if (mod == 2)
		return (0);
	for (i=1; i <= 25000000; i++)
	{
		m = (m * 2) % mod;
		if (m < 25000000 && niz[m])
		{
			pom = i - niz[m];
			break;
		}
		if (m < 25000000)
			niz[m] = i;
	}
	ret = ack(val - 1, pom);
	for (i=1, m=1; i <= ret; i++)
		m = (m * 2) % mod;
	return (m);
}

int				main()
{
	int			prevack = 1 + 3 + 7 + 61;
	long int	res = (ack(7, mod) + 2 * ack(10, mod) - (3 * 3) + prevack) % mod;

	printf("%ld\n", res);
	return 0;
}

