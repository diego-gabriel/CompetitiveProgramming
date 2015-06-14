#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

string getPat(string &cad){

	char k= cad[0];
	string res;
	res.push_back(k);
	for (int i = 1; i <cad.length(); i++){
		if (cad[i] != cad[i-1])
			res = res + cad[i];
	}

	return res;
}

int meFloor(double a, double b){
	double d = a / b;
	int ent = d;
	d = d - ent;
	return ent + (d >= 0.5 ? 1 : 0);
}

int abs(int v){
	return v < 0 ? -v : v;
}

int main(){
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		int n;
		bool ok = true;
		string cad, pat;
		cin>>n;
		vector <string> cads;
		cin>>cad;
		cads.push_back(cad);
		pat = getPat(cad);
		//cout<<"pat: "<<pat<<endl;
		int freq[pat.length()];
		memset(freq, 0, sizeof(freq));
		freq[0]++;
		int k = 0;
		for (int j = 1; j < cad.length(); j++){
			if (cad[j] != cad[j-1])
				k++;
			freq[k]++;
		}			

		for (int i = 1; i < n; i++){
			cin>>cad;
			cads.push_back(cad);
			ok = ok && getPat(cad) == pat;

			if (ok){
				freq[0]++;
				int k = 0;

				for (int j = 1; j < cad.length(); j++){
					if (cad[j] != cad[j-1])
						k++;
					freq[k]++;
				}
			}
		}

		if (ok){	
			int res = 0;
			for (int i = 0; i < pat.length(); i++){
				//cout<<pat[i]<<" =  "<<freq[i]<<" -> "<<meFloor(freq[i], n)<<endl;
				freq[i] = meFloor(freq[i], n);
			}
			//cout<<endl;
			for (int c = 0; c < cads.size(); c++){
				cad = cads[c];	
				int cont = 1;
				int k = 0;

				for (int i = 1; i < cad.length(); i++){
					if (cad[i] != cad[i-1]){
				//		cout<<"adding; "<<abs(freq[k]-cont)<<" on: "<<cad[i-1]<<" of "<<cad<<endl;
						res += abs(freq[k]-cont);
						k++;
						cont = 1; 
					}	
					else cont++;
				}	
					res += abs(freq[k]-cont);
			}

			cout<<"Case #"<<test<<": "<<res<<endl;	

		}
		else
			cout<<"Case #"<<test<<": Fegla Won"<<endl;
	}
}