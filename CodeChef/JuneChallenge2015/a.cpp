#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	long long t;
	cin>>t;

	while (t--){
		long long n;
		cin>>n;

		long long res = 0;
		long long allocated = 0;
		long long needed;
		for (long long i = 0; i < n; i++){
			cin>>needed;
			if (needed > allocated)
				res += needed - allocated;
			allocated = needed;
		}
		cout<<res<<endl;
	}
	return 0;
}