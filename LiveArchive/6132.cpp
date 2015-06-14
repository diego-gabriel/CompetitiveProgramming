#include <iostream>

using namespace std;

#define MOD (1000000000 + 7)

long long fact[350];

long long modPow(long long b, long long e)
{
	long long res = 1;

	if (e > 0)
	{
		if (e % 2 == 1)
		{
			res = b * modPow(b, e - 1);
		}
		else
		{
			res = modPow(b, e / 2);

			res *= res;
		}
	}

	return res % MOD;
}

long long invMod(long long n)
{
	return modPow(n, MOD - 2);
}


long long comb(long long n, long long k)
{
	long long res = 0;
	long long num, den;

	num = fact[n];
	den = (fact[k] * fact[n - k]) % MOD;

	den = invMod(den);

	res = num * den;

	return res % MOD;
}

int main()
{
	long long s, b;

	fact[0] = 1;

	for (long long i = 1; i < 350; i++)
	{
		fact[i] = (fact[i-1] * i) % MOD;
	}

	while (cin>>s>>b)
	{
		long long r1 = comb(b - 2 + s - 1, s);
		long long r2 = comb(b - 2 + s - 2, s-1);

		cout<<(r1 + r2) % MOD<<endl;
	}
	return 0;
}