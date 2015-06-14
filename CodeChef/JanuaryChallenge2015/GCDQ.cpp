#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int t;
	scanf("%d", &t);

	int a[100000+2];
	int l[100000+2];
	int r[100000+2];
	while (t--){
		int n, q;
		scanf("%d %d", &n, &q);
		l[0] = r[0] = l[n+1] = r[n+1] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		for (int i = 1; i <= n; i++){
			l[i] = gcd(a[i], l[i-1]);
		}
		for (int i = n; i >= 1; i--){
			r[i] = gcd(a[i], r[i+1]);
		}
		int R, L;
		for (int i = 0; i < q; i++){
			scanf("%d %d", &L, &R);
			printf("%d\n", gcd(l[L-1], r[R+1]));
		}



	}
	return 0;
}