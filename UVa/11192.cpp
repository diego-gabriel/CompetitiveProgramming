#include <iostream>

using namespace std;

string reverse(string cad){
	string res = "";

	for (int i = 0; i < cad.length(); i++){
		res = cad[i] + res;
	}

	return res;
}

string solve(string cad, int n){
	string buf = "";
	string res = "";
	int d = cad.length() / n;
	for(int i = 0; i < n; i++){
		buf = "";

		for (int j = 0; j < d; j++){
			buf = buf + cad[j+i*d];
		}

		res = res + reverse(buf);

	}
	return res;
}

int main(){
	int n;
	while (cin>>n && n){
		string cad;
		cin>>cad;
		cout<<solve(cad, n)<<endl;
	}
	return 0;
}