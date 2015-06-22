#include <iostream>	
#include <cstring>

using namespace std;

int main(){
	string cad;
	char k = 'a';

	cin>>cad;
	string cpy = cad;
	for(int i = cad.length()-2; i >= 0; i--){
		cpy[i] = max(cad[i], cpy[i+1]);
	}

	for(int i = 0, n = cad.length(); i < n; i++)
		if (cad[i] == cpy[i])
			cout<<cad[i];
	cout<<endl;
}