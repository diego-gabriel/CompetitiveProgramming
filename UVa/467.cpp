#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void read(vector <int> &v, string cad){
	int a = 0;

	for(int i = 0; i < cad.size(); i++){
		if (cad[i] == ' '){
			if (a != 0){
				v.push_back(a);
				a = 0;
			}
		}
		else{
			a *= 10;
			a += (cad[i] - '0');
		}
	}
}

int main(){
	string cad;
	int v;
	int test = 0;

	while(cin>>v){
		getline(cin, cad);
		vector <int> signals;
		signals.push_back(v);
		read(signals, cad + " ");
		int m = 100;
		for(int i = 0; i < signals.size(); i++){
			m = signals[i] < m ? signals[i] : m;

		}

		int s = m-5;
		bool ok = false;
		while (s < 3600 && !ok){
		//	cout<<s<<endl;
			ok = true;
			s++;
			for (int i = 0; i < signals.size() && ok; i++){
				ok = (s % (signals[i]*2)) < (signals[i] - 5);
			}

		}

		test++;
		if (ok){
			printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n", test, s/60, s%60);
		}
		else
			printf("Set %d is unable to synch after one hour.\n", test);

	}
	return 0;
}