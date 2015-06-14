#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int x[5];
	int a;
	while (scanf("%d", &a) == 1){
		memset(x, 0, sizeof(x));
		x[0] = a;
		for (int i = 1; i < 5; i++){
			scanf("%d", &a);
			x[i] += a;
		}
		for (int i = 0; i < 5; i++){
			scanf("%d", &a);
			x[i] += a;
		}

		bool ok = true;

		for (int i = 0; i < 5; i++){
			ok = ok && x[i] == 1;
		}

		if (ok)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}