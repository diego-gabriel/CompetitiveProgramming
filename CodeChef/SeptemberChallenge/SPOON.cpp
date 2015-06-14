#include <iostream>
#include <cmath>

using namespace std;

#define ll unsigned long long
#define MAX 1500000000

ll calcular(ll x)
{
	return (x * (x - 1))  / 2;
}

bool resuelve(ll x, ll &tar)
{
	ll c1, c2;
	c1 = calcular(x);
	c2 = calcular(x-1);


	return c1 >= tar && c2 < tar;
}


ll resolver (ll &x, ll min, ll max)
{

	ll res;

	ll mid = (min + max) / 2;

	if (resuelve(mid, x)) res = mid;
	else
	{
		ll calc = calcular(mid);

		if (calc > x) res = resolver(x, min, mid);
		else res = resolver(x, mid+1, max);
	}

	return res;
}

int main()
{
	int test;
	cin>>test;

	while (test--)
	{
		ll var;
		cin>>var;
		if (var == 2) cout<<2<<endl; else
		cout<<resolver(var, 2, MAX)<<endl;
	}
	return 0;
}