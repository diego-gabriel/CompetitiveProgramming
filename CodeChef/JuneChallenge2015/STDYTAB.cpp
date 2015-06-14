#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MOD 1000000000
long long s[2001][2001], count[2001][2001];

long long n, m, mod;

long long solve(){
	
	for (int x = 0; x <= n; x++){
		for (int y = 0; y <= m; y++){
			if (x == 0 || y == 0)
				s[x][y] = 1;
			else
				s[x][y] = (s[x-1][y]*count[y][m] + s[x][y-1]) % mod;
		}
	}

	return s[n][m];
}

int main(){
	long long t;
	mod = 1000000000;
	cin>>t;
	for (int x = 0; x < 2001; x++){
		for (int y = 1; y < 2001; y++){
			if (x == 0 || y == 1)
				count[x][y] = 1;
			else
				count[x][y] = (count[x-1][y] + count[x][y-1]) % mod;
		}
	}

	while (t--){

		cin>>n>>m;
		cout<<solve()<<endl;
	}
	return 0;
}