#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	int coin[5];
	coin[0] = 1;
	coin[1] = 5;
	coin[2] = 10;
	coin[3] = 25;
	coin[4] = 50;

	long long ways[30001];
	memset(ways, 0, sizeof(ways));
	ways[0] = 1;

	for (int c = 0; c < 5; c++){
		for (int i = 0; i < 30001; i++){
			if (i - coin[c] >= 0)
				ways[i] += ways[i-coin[c]];
		}
	}

	int n;

	while (scanf("%d", &n) == 1){
		if (ways[n] != 1)
			printf("There are %lld ways to produce %d cents change.\n", ways[n], n);
		else
			printf("There is only 1 way to produce %d cents change.\n", n);
	}

	return 0;
}