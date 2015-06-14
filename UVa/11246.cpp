#include <iostream>

using namespace std;

int main(){

	int t;
	cin>>t;
	while (t--){
		int n, k;
		cin>>n>>k;

		int res = n;
		bool in = false;
		while (n){
			
			if (in){
				res += n/k;
				n /= k;
			} else {
				res -= n/k;
				n /= k;
			}
			in = !in;
		}
		cout<<res<<endl;
	}

	return 0;
}