#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

int addAll(string cad){
	bool neg = false;
	int res = 0;

	for (int i = 0; i < cad.length(); i++){
		if (isdigit(cad[i])){
			int dig = cad[i] - '0';

			res = res + (neg ? -dig : dig);
		}
		else
			neg = cad[i] == '-';
	}

	return res;
}

bool check(int left, string cad){
	int right = 0;
	bool neg = false;

	for (int i = 0; i < cad.length(); i++){
		if (isdigit(cad[i])){
			int dig = cad[i] - '0';
			int cant = (neg ? -dig : dig);
			right += cant;
			left -= cant;
			//cout<<left<<" ---- "<<right<<endl;
		}
		else{
			neg = cad[i] == '-';
			int dig = cad[i+1]-'0';
			if (right == (neg ? (left + 2*dig) : left))
				return true;
		}
	}

	return false;
}

int main(){
	string cad;

	while (cin>>cad && cad != "*"){
		int totalSum = addAll(cad);
		if (check(totalSum, cad))
			cout<<"Possible"<<endl;
		else
			cout<<"Impossibru"<<endl;
	} 
	return 0;
}