#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MOD 1000000007
long long fact[600000];
int a;

long long f(long long n){
	return fact[n];
}

long long pow(long long b, long long e){
	long long res;
	if (e == 0)
		res = 1;
	else
	if (e % 2 == 1){
		res = (pow(b, e-1) * b) % MOD;
	}
	else{
		res = pow(b, e/2);
		res = (res*res) % MOD;
	}

	return res;
}

long long inv(long long n){
	return pow(n, MOD-2);
}

long long solve(long long k, long long n){
	long long res = 0;
	if (k >= 0){
		n = n+k-1;
		res = (f(n) * inv(f(k) * f(n-k) % MOD)) % MOD;
	}

	return res;
}

int main(){
	a =0;
	int n;
	cin>>n;
	fact[0] = 1;
	for (int i = 1; i < 600000; i++){
		fact[i] = (i * fact[i-1]) % MOD;
	}
	cout<<solve((n+1)/2 - 7, 7)<<endl;
	return 0;
}