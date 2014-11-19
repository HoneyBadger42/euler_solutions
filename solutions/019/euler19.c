#include <stdio.h>

# define START 1901
# define END 2001

int			main()
{
	int		d,m,y, leap, res=0;
	int		n[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	for(d=0,y=START; y < END; y++)
	{
		leap = (!(y%400) && !(y%4)) ? 1 : 0;
		for(m=0; m < 12; m++)
		{
			d = (m == 1 && leap) ? (d + 29) % 7 : (d + n[m]) % 7;
			res += (d == 6) ? 1 : 0;
		}
	}
	return (printf("%d\n", res));
}
