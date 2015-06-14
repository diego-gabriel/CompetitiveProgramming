#include <iostream>

using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}


int main(){
	int n;
	ll num, den;
	ll a, b;

	while (cin>>n && n != -1){
		num = 1;
		den = 1;
		for (int i = 0; i < n-1; i++){
			cin>>a>>b;
			num*=a;
			den*=b;
		}

		ll g = gcd(num, den);
		cout<<num/g<<" "<<den/g<<endl;

	}
}