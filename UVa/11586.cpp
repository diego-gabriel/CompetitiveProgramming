#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

pair <int, int> count(string cad){
	int m, f;
	m = f = 0;	
	for (int i = 0; i < cad.length(); i++){
		if (cad[i] == 'M') m++;
		if (cad[i] == 'F') f++;
	}

	return make_pair(m, f);
}

int main(){
	int t;
	string cad;
	cin>>t;
	cin.ignore();
	while (t--){
		getline(cin, cad);
		pair <int, int> res = count(cad);
		if ((res.first == res.second && res.first == 1) || res.first != res.second){
			cout<<"NO LOOP"<<endl;
		}
		else
			cout<<"LOOP"<<endl;

	}
	return 0;
}