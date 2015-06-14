#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 201
int coin[6];
int nCoins[MAX];
int iHaveCoin[6];
int coinsS[MAX];

void initCoins()
{
	coin[0] = 1;
	coin[1] = 2;
	coin[2] = 4;
	coin[3] = 10;
	coin[4] = 20;
	coin[5] = 40;
}

void initCoinsForShop()
{
	for (int i = 0; i < MAX; i++)
		coinsS[i] = 0x0ffffff0;
	coinsS[0] = 0;

	for (int i = 0; i < 6; i++)
	//	for (int t = 0; t < 201; t++)
		for (int j = MAX-1; j >= coin[i]; j--)
			coinsS[j] = min(coinsS[j], coinsS[j - coin[i]] + 1);

		/*for (int i = 0; i < MAX; i++)
			cout<<i/20<<"."<<(i*5)%100<<" = "<<coinsS[i]<<endl;*/
		
}

void init()
{
	initCoins();
	initCoinsForShop();
	for (int i = 0; i < MAX; i++)
		nCoins[i] = 0x0ffffff0;
	nCoins[0] = 0;

	for (int i = 0; i < 6; i++)
		for (int t = 0; t < iHaveCoin[i]; t++)
			for (int v = MAX-1; v >= coin[i]; v--)
				nCoins[v] = min(nCoins[v], nCoins[v - coin[i]] + 1);

}

int main()
{
	int in;
	double n;
	while (cin>>iHaveCoin[0]>>iHaveCoin[1]>>iHaveCoin[2]>>iHaveCoin[3]>>iHaveCoin[4]>>iHaveCoin[5] 
		&& (iHaveCoin[0] || iHaveCoin[1] || iHaveCoin[2] || iHaveCoin[3] || iHaveCoin[4] || iHaveCoin[5]))
	{
		cin>>n;
		n*=20;
		in = int(n);

		init();

		int res = 0x0ffffff0;
		for (int pay = in; pay <= MAX; pay++)
			res = min(res, nCoins[pay] + coinsS[pay - in]);

		printf("%3d\n", res);

	}
}