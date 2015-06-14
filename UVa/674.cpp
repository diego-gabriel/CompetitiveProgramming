#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 7490

int nCoins[MAX];
int coin[5];

void initCoin()
{
	coin[0] = 50;
	coin[1] = 25;
	coin[2] = 10;
	coin[3] = 5;
	coin[4] = 1;
}

void initChange()
{
	for (int i = 0; i < MAX; i++)
		nCoins[i] = 1;

	for (int i = 0; i < 4; i++)
	{ 
		for (int j = coin[i]; j < MAX; j++)
			nCoins[j] = nCoins[j] + nCoins[j - coin[i]];
	}
}

int main()
{
	initCoin();
	initChange();
	int n;
	while(scanf("%d", &n) == 1)
		printf("%d\n", nCoins[n]);
	return 0;
}