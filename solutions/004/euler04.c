#include <stdio.h>

int		main()
{
	int	i,j;

	for (i=999; i > 900; i--)
		for (j=i; j > 900; j--)
			if (((i*j)/100000) == ((i*j)%10))
				if (((i*j)/10000 % 10) == ((i*j)%100/10))
					if (((i*j)/1000 % 10) == ((i*j)%1000/100))
						return (printf("%d\n", i*j));
	return (0);
}
