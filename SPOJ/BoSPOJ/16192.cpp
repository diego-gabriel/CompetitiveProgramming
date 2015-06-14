#include <iostream>
#include <cstring>

using namespace std;

int n;
string comida[101][2];

bool isvowel(char k){
	return k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u';
}

string erase(string cad){
	string res = "";
	for (int i = 0; i < cad.length(); i++){
		if (isvowel(cad[i]))
			res = res + cad[i];
	}
	//cout<<("erased vowels "+cad+" ---> " + res)<<endl;
	return res;
}

string erase(string cad, string rem){
	string res = "";
	for (int i = 0; i < rem.length(); i++){
		bool exists = false;
		for (int j = 0; j < cad.length() && !exists; j++){
			exists = cad[j] == rem[i];
		}

		if (!exists)
			res = res + rem[i];
	}

	//cout<<("erased vowels: " + rem + " - " + cad + " -----> " + res)<<endl;
	return res;
}

bool solve(int i, string rem){
	bool res = rem == "";
	if (!res && i < n){
		string cad = erase(comida[i][0], rem);
		if (cad.length() < rem.length())
			res = solve(i+1, cad);
		if (!res)
			res = solve(i+1, erase(comida[i][1], rem));
	}
	return res;
}

int main(){
	string c;
	while(cin>>n && n){

		for (int i = 0; i < n; i++){
			cin>>c;
			comida[i][0] = erase(c);
			cin>>c;
			comida[i][1] = erase(c);
		}

		if (solve(0, "aeiou"))
			cout<<"EXISTE"<<endl;
		else
			cout<<"NO EXISTE"<<endl;
	}
}

