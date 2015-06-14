#include <iostream>

using namespace std;

int main(){
	string x;
	cin>>x;

	long long res = 0;

	for (int i = 0; i < x.length(); i++){
		int inv = 9 - (x[i]-'0');
		int n = x[i]-'0';
		if (inv < n){
			if (inv == 0 && i == 0)
				inv = n;
			res *= 10;
			res += inv;	
		}
		else{
			res *= 10;
			res += n;
		}
	}

	cout<<res<<endl;

	return 0;
}