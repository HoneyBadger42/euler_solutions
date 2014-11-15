#include <stdio.h>

int main()
{
	int a,b,c,res = 0;

	for (a=1,b=2,c=0; b <= 4000000; b=c)
	{
		c = a + b;
		res += (!(b % 2)) ? b : 0;
		a = b;
	}
	printf("%d\n", res);
}
