#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int t;
	cin>>t;

	while (t--){
		long long a, b;
		long long g;
		cin>>a>>b;

		while ((g = gcd(a, b)) != 1){
			b /= g;
		}

		if (b == 1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}