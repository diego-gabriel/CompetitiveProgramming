#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, l;
	cin>>n;
	while(n--){
		cin>>l;
		char k;
		long long c = 0;
		while (l--){
			cin>>k;
			c += (k == '1');
		}
		cout<<(c * (c+1))/2<<endl;

	}
	return 0;
}