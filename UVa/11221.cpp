#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <cstring>

using namespace std;

string filter(string cad){
	string res = "";

	for(int i = 0; i < cad.length(); i++){
		if (isalpha(cad[i])){
			res = res + cad[i];
		}
	}

	return res;
}

bool pal(string cad){

	for (int i = 0; i < cad.length(); i++){
		if (cad[i] != cad[cad.length()-1-i])
			return false;
	}

	return true;
}

int main(){
	int n;
	cin>>n;
	cin.ignore();
	int test = 0;
	while (n--){
		string cad;
		getline(cin, cad);

		cad = filter(cad);
		int k = sqrt(cad.length());
		bool ok = k*k == cad.length() && pal(cad);
		if (ok){
			char a[k][k];
			for (int i = 0; i < cad.length(); i++){
				a[i%k][i/k] = cad[i];
			}
			for (int i = 0; i < cad.length() && ok; i++){
				ok = a[i%k][i/k] == a[i/k][i%k];
			}
				
		}
		test++;
		cout<<"Case #"<<test<<":"<<endl;
		if (ok)
			cout<<k<<endl;
		else
			cout<<"No magic :("<<endl;

	}
	return 0;
}