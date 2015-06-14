#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int toInt(string cad){
	int res = 0;

	for (int i = 0; i < cad.length(); i++){
		res = res << 1;
		if (cad[i] == '1')
			res = res | 1;
	}

	return res;
}

int best (int pat){
	int res = 0;
	int cons = 0;
	while (pat){
		int bit = pat & 1;
		if (bit) cons++;
		else cons = 0;
		pat = pat >> 1;
		res = max(res, cons);
	}

	return res;
}

int main(){
	int nTest;
	cin>>nTest;
	bool first = true;
	while (nTest--){
		if (!first)
			cout<<endl;
		else 
			first = false;
		string cad;
		int n;
		cin>>cad;
		n = cad.length();
		int row[n];
		row[0] = toInt(cad);
		for (int i = 1; i < n; i++){
			cin>>cad;
			row[i] = toInt(cad);
		}

		int pat = 0xffffffff;
		int res = 0;
		for (int i = 0; i < n; i++){
			pat = 0xffffffff;
			int tam = 0;
			for (int j = i; j < n; j++){
				tam++;
				pat = pat & row[j];
				res = max(res, best(pat)*tam);
			}
		}

		cout<<res<<endl;
	}
	return 0;
}