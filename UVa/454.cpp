#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Palabra
{
	string frase;
	multiset<char> letras;
	Palabra(){
	}
	Palabra(string cad){
		for (int i = 0; i < cad.length(); i++){
			if (cad[i] != ' ')
				letras.insert(cad[i]);
		}
		frase = cad;
	}
};

bool operator == (Palabra a, Palabra b){
	return a.letras == b.letras;
}

bool operator < (Palabra a, Palabra b){
	return a.frase < b.frase;
}

int main(){
	int n;
	bool fst = true;
	cin>>n;
	cin.ignore();
	cin.ignore();
	while (n--){

		string cad;
		vector <Palabra> v;
		while (getline(cin, cad) && cad != ""){
			v.push_back(Palabra(cad));
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++){
			for (int j = i+1; j < v.size(); j++){
				if (v[i] == v[j])
					cout<<v[i].frase + " = " + v[j].frase<<endl;
			}
		}
		if (n) cout<<endl;
	}

	return 0;
}