#include <iostream>
#include <cstring>

using namespace std;

bool isPal(string cad){
	bool ok = true;

	for(int i = 0; i < cad.length()/2; i++){
		ok = ok && (cad[i] == cad[cad.length()-1-i]);
	}

	return ok;
}

int main(){
	string cad;
	cin>>cad;
	int k;
	cin>>k;

	bool ok = cad.length()%k == 0;

	if (ok){
		int t = cad.length()/k;	
		for (int i = 0; i < k; i++){
			string msg = "";
			for (int j = i*t; j < t*(i+1); j++){
				msg = msg + cad[j];
			}

			ok = ok && isPal(msg);
		}
	}

	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}