#include <stdio.h>

# define MAX 1000

int		main()
{
	int	i,j,tmp,res;
	int	arr[MAX] = {0};

	arr[MAX-1] = 1;
	for (i=1,tmp=1; i <= MAX; i++)
	{
		for (j=0; j < tmp; j++)
			arr[MAX-j-1] = arr[MAX-j-1] * 2;
		for (j=0; j < tmp; j++)
		{
			arr[MAX-j-2] += arr[MAX-j-1] / 10;
			if (arr[MAX-j-2] > 0)
				tmp = (tmp > (j + 2)) ? tmp : (j + 2);
			arr[MAX-j-1] = arr[MAX-j-1] % 10;
		}
	}
	for (i=0, res=0; i <= tmp; i++)
		res += arr[MAX-1-tmp+i];
	return (printf("%d\n", res));
}
