#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	const int size=2000000;
	bool flag = true;
	int* primes = new int[size];
	int primenumber=1;
	unsigned long long int primesums=2;
	primes[0]=2;
	primes[size-1]=1;
	for(int i=3;i<size;i+=2)
	{
		flag= true;
		for(int k=0;primes[k]<=sqrt(i);k++)
		if(!(i%primes[k]))
		{
			flag=0;
			break;
		}
		if(flag)
		{
			primes[primenumber] = i;
			primesums+=i;
			primenumber++;
		}
	}
	cout<<primesums<<endl;
	delete primes;
	return 0;
}
