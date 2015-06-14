#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a%b);
}

int main(){
	int t;
	cin>>t;
	while (t--){
		long long n, d;
		cin>>n>>d;

		long long res = 1;
		long long v;
		for (int i = 0; i < n; i++){
			cin>>v;
			v -=d;
			res = (res*v)/gcd(res, v);
		}
		cout<<res<<endl;
	}
	return 0;
}