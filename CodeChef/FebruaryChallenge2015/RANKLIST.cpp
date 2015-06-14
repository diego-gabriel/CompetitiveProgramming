#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long n, s;
	long long nTest;
	cin>>nTest;
	while (nTest--){
		cin>>n>>s;
		long long ideal = (n+1)*n/2;
		long long res = 0;
		int candidate = n-1;
		while (ideal != s){
			if (ideal - candidate >= s){
				ideal -= candidate;
				res++;
			}
			candidate--;
		}

		cout<<res<<endl;
	}
	return 0;
}