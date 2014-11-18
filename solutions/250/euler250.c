#include <stdio.h>

#define TS 10000000000000000LL
#define M 250250

long long		sume[2][250];

int				main()
{
	int			n,n1,n2,i,j;
	long long	*s,*t,*u;

	s = sume[0];
	t = sume[1];
	s[1] = 1;
	for (n=2; n <= M; n++)
	{
		for (n2=1, n1=n, i=1; i <= n; i <<= 1)
		{
			n1 %= 250;
			n2 = (i&n) ? (n2 * n1) % 250 : n2;
			n1 *= n1;
		}
		for (i=0; i < 250; i++)
		{
			j = (i + n2 >= 250) ? (i + n2 - 250) : i + n2;
			t[j] = s[i] + s[j];
			t[j] -= (t[j] >= TS) ? TS : 0;
		}
		u = t;
		t = s;
		s = u;
		s[n2]++;
		s[j] -= (s[j] >= TS) ? TS : 0;
	}
	return (printf("%lld\n",s[0]));
}
