#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 1000000007

int main(){
	int n;
	cin>>n;
	string cad;
	for (int i = 0; i < n; i++){
		cin>>cad;
		int res = 1;
		bool odd = true;
		for (int j = 0; j < cad.length(); j++){
			char k = cad[j];
			if (odd){
				odd = false;
				if (k == 'l')
					res = res*2;
				else
					res = res*2 + 2;
			}
			else{
				odd = true;
				if (k == 'l')
					res = res*2-1;
				else
					res = res*2+1;
			}
			res = res % MOD;
		}
		cout<<res<<endl;
	}

}
