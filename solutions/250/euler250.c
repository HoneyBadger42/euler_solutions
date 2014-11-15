#include <stdio.h>

#define BIG 10000000000000000LL

long long		sume[2][250];

int				main()
{
	int			b,n,i,j,p;
	long long	*s,*t,*u;

	s = sume[0];
	t = sume[1];
	s[1] = 1;
	for (n=2; n <= 250250; n++)
	{
		p = 1;
		b = n;
		for (i=1; i <= n;i <<= 1)
		{
			b %= 250;
			if (i & n)
				p = (p * b) % 250;
			b *= b;
		}
		for (i=0; i < 250; i++)
		{
			j = (i + p >= 250) ? (i + p - 250) : i + p;
			t[j] = s[i] + s[j];
			t[j] = (t[j] >= BIG) ? (t[j] - BIG) : t[j];
		}
		u = t;
		t = s;
		s = u;
		s[p]++;
		s[j] = (s[j] >= BIG) ? s[j]-BIG : s[j];
	}
	return (printf("%lld\n",s[0]));
}
