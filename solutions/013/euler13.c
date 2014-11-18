#include <stdio.h>

# define CUT 1000000000000000000000000000000000000000000.0L

int				main()
{

	long double	tmp,sum;
	FILE		*fd = fopen("numlist.txt", "r");

	if (!fd)
		return (-1);
	while (fscanf(fd, "%llf", &tmp) > 0)
		sum += tmp;
	fclose(fd);
	return (printf("%ld\n", (long int)(sum / CUT)));
}
