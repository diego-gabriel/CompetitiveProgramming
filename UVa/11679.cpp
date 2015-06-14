#include <iostream>

using namespace std;

struct Bank
{
	int in, out;
	Bank(){in = out = 0;}
	bool ok(){
		return in >= out;
	}
	void deb(int m){
		out += m;
	}
	void acr(int m){
		in += m;
	}
};

int main(){
	int nBank, nDeb;
	while(cin>>nBank>>nDeb && (nBank || nDeb)){
		Bank banks[nBank+1];
		int o, d, m;
		for (int i = 1; i <= nBank; i++){
			cin>>banks[i].in;
		}
		for (int i = 0; i < nDeb; i++){
			cin>>o>>d>>m;
			banks[o].deb(m);
			banks[d].acr(m);
		}

		bool res = true;
		for (int i = 1; i <= nBank && res; i++){
			res = banks[i].ok();
		}
		if (res) cout<<"S"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}