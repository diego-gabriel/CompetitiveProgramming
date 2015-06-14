#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
	return b == 0 ? a : gcd(b, a%b);
}

unsigned long long lcm (unsigned long long a, unsigned long long b){
	return a*(b/ gcd(a, b));
}

int main(){
	string cad;

	while (cin>>cad && cad != "*"){
		vector <unsigned long long> no, yes;

		for (int i = 0; i < cad.length(); i++){
			if (cad[i] == 'Y')
				yes.push_back(i+1);
			else no.push_back(i+1);
		}
		unsigned long long res = 1;
		for (int i = yes.size()-1; i >= 0; i--){
			res = lcm(res, yes[i]);
			//cout<<res<<endl;
		}

		bool ok = true;

		for (int i = no.size()-1; i >= 0 && ok; i--){
			ok = res % no[i] != 0;
		}

		if (ok)
			cout<<res<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}