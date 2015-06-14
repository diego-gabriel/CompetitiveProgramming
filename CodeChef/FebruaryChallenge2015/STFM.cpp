#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

unsigned long long MOD, n;
vector<unsigned long long> fact;
vector<unsigned long long> sumaRara;

unsigned long long min(unsigned long long a, unsigned long long b){
	return a < b ? a : b;
}

void initFact(){
	fact.assign(MOD+1, 0);
	fact[0] = 1 % MOD;
	for (unsigned long long i = 1; i < MOD; i++){
		fact[i] = (fact[i-1]*i) % MOD;
	}
}

unsigned long long f(unsigned long long n){
	return fact[min(n, MOD)];
}

unsigned long long sq(unsigned long long n){
	return (n*n) % MOD;
}

void initf2(){
	sumaRara.assign(MOD+1, 0);
	sumaRara[1] = 1 % MOD;

	for (unsigned long long i = 2; i <= MOD; i++){
		unsigned long long nT = (f(i-1)*sq(i)) % MOD;
		sumaRara[i] = (sumaRara[i-1] + nT) % MOD;
	}
}

unsigned long long s1(unsigned long long n){
	return sumaRara[min(n, MOD)];
}

unsigned long long s2(unsigned long long x){
	unsigned long long res = x;
	unsigned long long lx = x;
	x = x % MOD;
	if (lx % 2 == 0){
		res = (x * ((lx/2) % MOD)) % MOD;
		res = (res * (x+1)) % MOD;
	}
	else{
		res = (x*(((lx+1)/2) % MOD)) % MOD;
		res = (res * x) % MOD;
	}
	return res;
}

int main(){
	cin>>n>>MOD;
	initFact();
	initf2();
	unsigned long long res = 0;
	unsigned long long p;
	for (int i = 0; i < n; i++){
		cin>>p;

		res += (s1(p) + s2(p) % MOD);
		//cout<<
		res %= MOD;
	}
	cout<<res<<endl;
	return 0;
}