#include <iostream>
#include <set>
#include <ctype.h>
#include <cstring>

using namespace std;

void initBeb(set<string> &cad){
	cad.insert("fernet");
	cad.insert("caipirinha");
	cad.insert("cerveza");
	cad.insert("ron");
	cad.insert("vodka");
	cad.insert("whisky");
	cad.insert("singani");
}

bool isnumeric(string cad){
	bool res = true;

	for (int i = 0; i < cad.length() && res; i++){
		res = isdigit(cad[i]);
	}

	return res;
}

bool menor(string cad){
	long long num = 0;

	for (int i = 0; i < cad.length(); i++){
		num *= 10;
		num += (cad[i]-'0');
	}

	return num < 18;
}

int main(){
	set <string> bebidas2;
	initBeb(bebidas2);
	int nTest;
	cin>>nTest;

	while(nTest--){
		int n;
		cin>>n;
		string cad;
		int menores = 0;
		int bebidas = 0;
		while (n--){
			cin>>cad;
			if (isnumeric(cad) && menor(cad)){
				menores++;
			}
			else
			if (bebidas2.find(cad) != bebidas2.end())
				bebidas++;
		}

		cout<<min(menores, bebidas)<<endl;
	}
}