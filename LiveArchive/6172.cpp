#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map <unsigned long long, unsigned long long> memo;

unsigned long long solve(unsigned long long n){

	if (memo[n] == 0){
		memo[n] = n == 1 ? 1 : max(n, solve(n % 2 == 0 ? n/2 : 3*n+1));
	}

	return memo[n];
}

int main(){
	int n;
	cin>>n;
	while (n--){
		int k;
		unsigned long long v;
		cin>>k>>v;

		cout<<k<<" "<<solve(v)<<endl;
	}
	return 0;
}