#include <iostream>
#include <map>
#include <cstring>

using namespace std;


bool solve(string cad){
	bool res = (cad.length() % 8) == 0;
	if (res){
		map <char, int> r;
		int k = cad.length() / 8;
		for (int i = 0; i < cad.length(); i++){
			r[cad[i]]++;
		}

		res = r['c'] == k*3 && r['h'] == k*2 && r['a'] == k && r['u'] == k*2;
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	while (n--){
		string cad;
		cin>>cad;
		if (solve(cad)) cout<<"SI"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}