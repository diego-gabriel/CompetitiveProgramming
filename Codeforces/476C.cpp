#include <iostream>

using namespace std;

#define MOD 1000000007


int main(){

	long long a, b;
	cin>>a>>b;
	long long sum = b*(b-1) / 2;
	sum = sum % MOD;

	long long res = 0;

	for(long long k = 1; k <= a; k++){
		long long t1 = k*b % MOD;
		t1 = t1*sum % MOD;
		t1 += sum;
		t1 = t1 % MOD;

		res += t1;
		res = res % MOD;
	}

	cout<<res<<endl;

	return 0;
}