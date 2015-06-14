#include <iostream>

using namespace std;

long long max(long long a, long long b){
	return a > b ? a : b;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		int k;
		cin>>n>>k;
		long long a[n];
		for (int i = 0; i < n; i++)
			cin>>a[i];
		long long b;
		long long res = 0;
		for (int i = 0; i < n; i++){
			cin>>b;
			res = max(res, k/a[i] * b);
		}
		cout<<res<<endl;
	}
	return 0;
}