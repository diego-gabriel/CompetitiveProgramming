#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		string cad;
		cin>>cad;
		int res = 0;
		for (int i = 1; i < cad.length(); i++){
			if (islower(cad[i-1]) && isupper(cad[i]))
				res++;
		}
		cout<<res<<endl;
		
	}
	return 0;
}