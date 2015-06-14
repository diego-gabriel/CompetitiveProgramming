#include <iostream>
#include <cstring>

using namespace std;


long long n, k, MOD;
long long pow[1005];

long long f(long long n){
	long long res;
	if (n == 0)
		res = 1;
	else{
		res = 9*pow[n-1];
	}
	return res;
}

long long nOfDiv(long long l, long long s){
	long long up = pow[l]-1;
	long long down = pow[l-1]-1;
	return ((up / s) - (down / s)+ MOD) % MOD;
}

long long solve(long long l, long long s){
	long long res = 0;

	for (int i = 1; i <= l; i++){
		res += (nOfDiv(i, s) * f(l-i));
		cout<<"long "<<i<<" -> "<<res<<endl;
		res = res % MOD;
		for (int j = i+1; j <= l; j++){
			res = (res + MOD - nOfDiv(j, s) + nOfDiv(i, s)) % MOD;
		}

		cout<<"long 2"<<i<<" -> "<<res<<endl;
	}

	return res;
}


int main(){
	cin>>n>>k>>MOD;
	memset(pow, 0, sizeof(pow));
	pow[0] = 1;
	for (int i = 1; i < 1005; i++){
		pow[i] = (pow[i-1] * 10) % MOD;
	}
	cout<<solve(n, k)<<endl;
}