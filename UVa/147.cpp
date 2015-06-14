#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

long long res[6001];
int coin[11];

int initCoins()
{
	coin[0] = 1;
	coin[1] = 2;
	coin[2] = 4;
	coin[3] = 10;
	coin[4] = 20;
	coin[5] = 40;
	coin[6] = 100;
	coin[7] = 200;
	coin[8] = 400;
	coin[9] = 1000 ;
	coin[10] = 2000;
}

void init()
{
	initCoins();
	memset(res, 0, sizeof(res));
	res[0] = 1;

	for (int i = 0; i < 11; i++)
	{
		for (int c = coin[i]; c < 6001; c++)
			res[c] += res[c - coin[i]];
	}

}

int main()
{
	init();
	double n;
	int in;

	while (cin>>n && n != 0.00)
	{
		in = n * 20;
		printf("%6.2f%17lld\n", n, res[in]);
	}
	return 0;
}

