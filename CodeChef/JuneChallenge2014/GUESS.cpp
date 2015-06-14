#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	long long t, n, m;

	cin>>t;
	while (t--){
		cin>>n>>m;
		long long a, b;
		a = m*n/2;
		b = m*n;
		long long g = gcd(a, b);
		cout<<a/g<<"/"<<b/g<<endl;
	}
	return 0;
}