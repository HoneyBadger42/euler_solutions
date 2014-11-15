#include <stdio.h>

int				main(void)
{
	long long	n1,n2,n3;

	for (n1=1; n1 <= 1000; n1++)
		for (n2=n1+1; n2 <= 1000; n2++)
			for (n3=n2+1; n3 <= 1000; n3++)
				if (((n1 * n1) + (n2 * n2) == (n3 * n3)) && (n1 + n2 + n3 == 1000))
					return (printf("%lld\n", n1 * n2 * n3));
	return (0);
}
