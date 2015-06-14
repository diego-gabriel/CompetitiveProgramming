#include <iostream>

using namespace std;

#define MOD 1000000009

int main()
{
	long long puntos = 0;
	long long m, n, k;
	long long cont;

	cin>>n>>m>>k;

	while (n < m + ((m/(k-1) + ((m % (k-1)) > 0)) -1))
	{
		puntos += k;
		puntos = puntos % MOD;
		puntos *= 2;
		puntos = puntos % MOD;
		m -= k;
		n -= k;
	}

	puntos += m;

	cout<<puntos<<endl;


	return 0;
}