#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		long long s, c, k;
		cin>>s>>c>>k;
		long long i = s - k+1;
		if (i > 0){
			if (c >= i)
					i++;
			long long res = (1<<i) + 1;
			cout<<res<<endl;
		}
		else
			if (s == 0 && k == 1)
				cout<<(1<<(c+1))<<endl;
			else
			cout<<0<<endl;
	}
	return 0;
}