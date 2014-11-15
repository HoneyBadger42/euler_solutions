#include <math.h>
#include <stdio.h>
#define MAX 11400

long double		divisor = 10000.0;
long double		tmp = 0 - M_PI;

/////////////////////////////////
// compile: gcc -lm euler461.c //
/////////////////////////////////

long double				eulerRes(long double n)
{
	return ((long double)exp((long double)n / (long double)divisor) - 1);
}

long double				dAbs(long double n)
{
	return ((n < 0) ? (long double)(-1.0 * n) : n);
}

int					getSum(double n1, double n2, double n3, double n4)
{
	return ((int)((n1*n1) + (n2*n2) + (n3*n3) + (n4*n4)));
}

int					calc(long n1, long n2, double n3, double n4)
{
	int				ret;
	long double		res;

	res = (long double)0.0;
	res += eulerRes(n1);
	res += eulerRes(n2);
	res += eulerRes(n3);
	res += eulerRes(n4);
	if (res >= (long double)3.14159260 && res <= (long double)3.14159266)
		if (dAbs(res - M_PI) < dAbs(tmp))
		{
			tmp = res - M_PI;
			ret = getSum(n1,n2,n3,n4);
			printf("[%d, %d, %d, %d]", (int)n1++, (int)n2, (int)n3, (int)n4);
			printf(" -> %d\n", ret);
		}
	return (ret);
}

int					main()
{
	int				ret;
	double			n1, n2, n3, n4;

	//	initTab();
	//	for (n1=1433.0; n1 < MAX; n1 += (long double)1.0)
	//		for (n2=2147.0; n2 < MAX; n2 += (long double)1.0)
	//			for (n3=4903.0; n3 < MAX; n3 += (long double)1.0)
	//				for (n4=11000.0; n4 < MAX; n4 += (long double)1.0)
	for (n1=1430; n1 < 1450; n1 += 1)
		for (n2=2100; n2 < 2200; n2 += 1)
			for (n3=4900; n3 < 5000; n3 += 1)
				for (n4=11300; n4 < 11400; n4 += 1)
					ret = calc(n1,n2,n3,n4);
	return (printf("\nEuler 461: \033[96m%d\033[0m\n", ret));
}
