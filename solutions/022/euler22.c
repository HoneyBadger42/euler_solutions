#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

# define BUFSIZE 64000

int			MAX = 1;

char		**ft_strsplit(char *str)
{
	char	**res;
	int		i,j,k;

	for (i=0; str[i]; i++)
		MAX += (str[i] == ',') ? 1 : 0;
	res = (char **)malloc(sizeof(char *) * MAX + 1);
	for (k = 0; k < MAX + 1; k++)
		res[k] = (char *)malloc(sizeof(char) * 32);
	for (k=0,i=0,j=0; str[i]; i++)
	{
		if (str[i] == ',')
		{
			res[k++][j] = '\0';
			j = 0;
		}
		else
			if (str[i] != '"')
				res[k][j++] = str[i];
	}
	return (res);
}

int			alphacmp(const void *p1, const void *p2)
{
	return (strcmp(*(char *const *)p1, *(char *const *)p2));
}

int			main()
{
	int		i, j, fd, c, res = 0;
	char	*buf, **t;

	fd = open("p022_names.txt", O_RDONLY);
	buf = (char *)malloc(sizeof(char) * BUFSIZE + 1);
	if (!fd)
		return (-1);
	while ((c = read(fd, buf, BUFSIZE)) > 0)
		t = ft_strsplit(buf);
	close(fd);
	qsort(&t[0], MAX, sizeof(char *), alphacmp);
	for (i=0; t[i][0] >= 'A' && t[i][0] <= 'Z'; i++)
	{
//	printf("%s\n", t[i]);
		for (j=0, c=0; t[i][j]; j++)
			c += (t[i][j] - '@');
		res += c * (i + 1);
	}
	return (printf("%d\n", res));
}
