#include <iostream>

using namespace std;

long long abs(long long a){
	return a < 0 ? -a : a;
}

int main(){
	long long t;
	cin>>t;
	while (t--){
		long long n;
		cin>>n;
		long long d = 0;
		long long v;
		long long res = 0;
		for (long long i = 0; i < n; i++){
			cin>>v;
			d += v;
			res += abs(d);

		}

		cout<<res<<endl;
	}
	return 0;
}