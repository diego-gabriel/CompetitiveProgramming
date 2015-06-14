#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
unsigned long long n, m, q, r;
unsigned long long memo[100000+100];
unsigned long long pow(unsigned long long n, unsigned long long e){
	return e == 0 ? 1 : n*pow(n, e-1);
}

unsigned long long modpow(unsigned long long b, unsigned long long e){
	unsigned long long res;
	if (e == 0){
		res = 1;
	}
	else
	if (e % 2 == 1){
		res = (b * modpow(b, e-1)) % m;
	}
	else{
		res = modpow(b, e/2);
		res = (res*res) % m;
	}
	return res;
}


unsigned long long ff(unsigned long long i){
	return i == 0 ? 1 : pow(i, i)*ff(i-1);
}

void solve(){
	cin>>r;
	unsigned long long res;
	if (n <= 5){
		res = ff(n)/(ff(r)*ff(n-r));
		res %= m;
	}
	else{
		unsigned long long num = memo[n];
		unsigned long long den = modpow((memo[r]*memo[n-r])%m, m-2);
		res = (num*den)%m;
	}
	cout<<res<<endl;
}

int main(){
	unsigned long long t;
	cin>>t;

	while (t--){
		memo[0] = 1;
		cin>>n>>m>>q;

		for (unsigned long long i = 1; i <= n; i++)
			memo[i] = (memo[i-1]*modpow(i, i))%m;
	
		for(unsigned long long i = 0; i < q; i++){
			solve();
		}
	}
	return 0;
}