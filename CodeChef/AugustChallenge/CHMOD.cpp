#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int tab[100001][25];
long long primos[25];

int i;
int y;
inline void update (int pos, int n)
{
	int p, primo;
	p = 0;

	for (i = 0; i < 25; i++)
	{
		tab[pos][i] = tab[pos-1][i];
	}

	while (n > 1)
	{
		primo = primos[p];

		if (n % primo == 0)
		{
			n /= primo;
			tab[pos][p]++;
		} else p++;
	}
}

long long modPow(long long &b, long long e, long long &mod)
{
	long long res = 1;
	long long pot = b;
	
	while (e)
	{
		if (e & 1) res = (res * pot) % mod;
		e >>= 1;	
		pot = (pot * pot) % mod;
	}

	return res;
}

inline int query (int rigth, int left, long long mod)
{
	long long res = 1;
	long long pot;
	for (i = 0; i < 25; i++)
	{
		pot = modPow(primos[i], tab[left][i] - tab[rigth][i], mod);

		res = (res * pot) % mod;
	}

	return res;
}

int main()
{
	bool p[101];
	memset(p, true, sizeof(p));
	p[0] = p[1] = false;

	for (i = 2; i <= 10; i ++)
	{
		if (p[i])
		{
			for (int j = 2*i; j <= 100; j += i)
			{
				p[j] = false;
			}
		}
	}

	int c = 0;
	for (i = 0; i < 101; i++)
	{
		if (p[i]) {
			primos[c] = i;
			c++;
		}
	}

	int n, v;

	scanf("%d", &n);

	for (i = 0; i < 25; i++)
		tab[0][i] = 0;

	int a, b;


	for (y = 0; y < n; y++)
	{
		scanf("%d", &v);

		update(y+1, v);
	}

	int nQ;

	scanf("%d", &nQ);

	int r, l, mod;
	for (y = 0; y < nQ; y++)
	{
		scanf("%d %d %d", &r, &l, &mod);

		printf("%d\n", query(r-1, l, mod));
	}
} 

