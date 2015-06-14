#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	int n;

	cin>>t;
	while (t--){
		cin>>n;
		long long res = 0;
		for (int i = 1; i < sqrt(n+1); i++){
			if (n % i == 0){
				res += i;
				if (i * i != n){
					res += n/i;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}