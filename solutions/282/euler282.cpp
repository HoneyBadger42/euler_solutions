#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

#define gr 25000000

long		mod = 1475789056;

long int	rek(int A, int mod)
{
	long m=1, pom, suma, i;

	if (A == 1)
		return 2;
	if (mod == 2)
		return 0;
	vector <int> niz(gr,0);
	for (i=1; i <= gr; i++)
	{
		m = (m * 2) % mod;
		if (m < gr && niz[m])
		{
			pom = i - niz[m];
			break;
		}
		if (m < gr)
			niz[m] = i;
	}
	suma = rek(A - 1, pom);
	m = 1;
	for (i=1; i <= suma; i++)
		m = (m * 2) % mod;
	return m;
}

int			main()
{
	int		prevAck = 1 + 3 + 7 + 61;
	printf("%ld\n", (rek(7, mod) + 2 * rek(10, mod) - 9 + prevAck) % mod);
	return 0;
}

