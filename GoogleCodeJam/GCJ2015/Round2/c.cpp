#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <map>

using namespace std;

map <int, int> nBit;

void init(){
	int p = 1;

	for (int i = 0; i < 22; i++){
		nBit[i] = p;
		p *= 2;
	}
}

vector <string> split(string cad){
	string buff = "";
	vector <string> res;

	for (int i = 0; i < cad.length(); i++){
		if (cad[i] == ' '){
			if (buff != ""){
				res.push_back(buff);
				buff = "";
			}
		} else
			buff = buff + cad[i];
	}

	if (buff != ""){
		res.push_back(buff);
		buff = "";
	}

	return res;
}

int main(){

	int t;
	cin>>t;
	init();
	for(int test = 1; test <= t; test++){
		int n;
		cin>>n;
		cin.ignore();
		string cad;
		set<string> en, fr, am;
		vector <string> words;
		getline(cin, cad);
		words = split(cad);
		int res = 0;
		for (int i = 0; i < words.size(); i++){
			en.insert(words[i]);
		}

		getline(cin, cad);
		words = split(cad);

		for (int i = 0; i < words.size(); i++){
			fr.insert(words[i]);
			if (en.find(words[i]) != en.end())
				am.insert(words[i]);
		}
		res = am.size();
		//cout<<"until now res: "<<res<<endl;
		vector <vector <string> > lines; 
		for (int i = 2; i < n; i++){
			getline(cin, cad);
			lines.push_back(split(cad));
		}

		int nD;
		if (n == 2)
			nD = 0;
		else{
			nD = 0x6fffffff;
			res = 0;
		}

		for (int i = 0; i < 1<<(n-2); i++){
			int bitMask = i;
			set<string> ena, fra, ama;
			ena = en;
			fra = fr;
			ama = am;
			int bit;
			int acum = 0;
			for (int i = 0; i < n-2; i++){
				bit = bitMask & (1<<i);
				if (ama.size() > nD)
					break;
				if (bit > 0){
					//en
					//cout<<"english"<<endl;
					for (int j = 0; j < lines[i].size(); j++){
						ena.insert(lines[i][j]);
						if (fra.find(lines[i][j]) != fra.end()){
							ama.insert(lines[i][j]);
						}
					}

				}
				else{
					//fr
					//cout<<"french<"<<endl;
					for (int j = 0; j < lines[i].size(); j++){
						fra.insert(lines[i][j]);
						if (ena.find(lines[i][j]) != ena.end()){
							ama.insert(lines[i][j]);
						}
					}
				}
			}
			//cout<<"bitmask: "<<bitMask<<" acum; "<<acum<<endl;

			nD = nD < ama.size() ? nD : ama.size();
		}

		cout<<"Case #"<<test<<": "<<res+nD<<endl;

	}

	return 0;
}