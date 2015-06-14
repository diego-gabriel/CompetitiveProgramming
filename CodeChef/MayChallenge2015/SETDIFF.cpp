#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		long long s[n];
		for(int i = 0; i <n ; i++){
			cin>>s[i];
		}

		sort(s, s+n);

		long long minims = 0;
		long long maxims = 0;
		long long p = 1;
		for (int i = 0; i < n; i++){
			minims += p*s[n-1-i];
			maxims += p*s[i];
			p *= 2;

			minims %= MOD;
			maxims %= MOD;
			p %= MOD;
		}

		cout<<(maxims+MOD - minims) % MOD<<endl;
	}
}