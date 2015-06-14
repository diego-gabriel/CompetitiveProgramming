#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int main(){

	int nT;
	cin>>nT;
	for (int t = 0; t < nT; t++){
		int n;
		cin>>n;
		string cad;
		set<string> st;
		string aux;
		int res = 0;
		for (int i = 0; i < n; i++){
			cin>>cad;	
			bool ok = false;
			aux = "";
			for (int k = 0; k < cad.length(); k++){
				aux = aux + cad[k];
				if (!ok && st.find(aux) == st.end()){
					ok = true;
					res += aux.length();
				}
				st.insert(aux);
			}

		}
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;
}
