#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int t;

	int n;
	int idx = 0;
	int count[100000+5];
	int a, i;
	scanf("%d", &t);
	while (t--){
		memset(count, 0, sizeof(count));
		idx = 0;
		scanf("%d", &n);
		int a;
		for (i = 0; i < n; i++){
			scanf("%d", &a);
			count[a]++;
			if (count[a] > count[idx]){
				idx = a;
			}
		}
		printf("%d\n", n-count[idx]);
	}
	return 0;
}