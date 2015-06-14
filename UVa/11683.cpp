#include <iostream>
#include <cstdio>

using namespace std;

int h, w, cLevel, res, n;

int main(){

	while (scanf("%d", &h) && h){
		scanf("%d", &w);

		cLevel = h;
		res = 0;
		while(w--){
			scanf("%d", &n);
			if (cLevel < n)
				res += (n - cLevel);
			cLevel = n;
		}

		res += (h - cLevel);
		printf("%d\n", res);

	}
}