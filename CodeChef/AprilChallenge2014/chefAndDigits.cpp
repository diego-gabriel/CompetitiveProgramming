#include <iostream>

using namespace std;

int abs(int a){
	return a < 0 ? -a : a;
}

int main(){
	int n, m;
	cin>>n>>m;
	int dp[10][100001], a[100001];
	for (int i = 1; i <= n; i++){
		char k;
		cin>>k;
		a[i] = (k - '0');
	}

	for (int i = 0; i < 10; i++){
		dp[i][0] = 0;
		for (int j = 1; j <= n; j++)
			dp[i][j] = dp[i][j-1] + abs(i-a[j]);
	}

	for (int i = 0; i < m; i++){
		int k;
		cin>> k;
		int num = a[k];
		cout<<dp[num][k-1]<<endl;
	}
	return 0;
}