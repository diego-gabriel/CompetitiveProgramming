#include <cstdio>
#include <cstring>

using namespace std;

long long memo[505][505];

long long solve(long long last, long long n){
	if (memo[last][n] == -1){
		long long  res = 0;
		if (n == 0)
			res = 1;
		else{
			for (int i = last+1; i <= n; i++){
				res += solve(i, n-i);
			}
		}
		memo[last][n] = res;
	}


	return memo[last][n];
}

int main(){

	int n;
	scanf("%d", &n);
	for (int i = 0; i < 505; i++){
		for (int j = 0; j < 505; j++)
			memo[i][j] = -1;
	}
	printf("%lld\n", solve(0, n)-1);

	return 0;
}