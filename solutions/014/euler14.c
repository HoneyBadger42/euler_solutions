#include <stdio.h>

# define MAX 1000000

int					main()
{
	unsigned int	i,j,n,tmp,res=0;

	for (i=(MAX*4/5),tmp=0; i <= MAX; i++)
		for (j=i, n=0; j != 1; n++)
		{
			if (n > tmp)
			{
				tmp = n;
				res = i;
			}
			j = (!(j%2)) ? (j/2) : (3*j+1);
		}
	return (printf("%d\n", res));
}
