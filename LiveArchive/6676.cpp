#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool match(string cad, string p){
	bool res= true;
	for (int i = 0; i < 9 && res; i++){
		res =  (cad[i] == '*' || cad[i] == p[i]);
	}
	return res;
}

int main(){
	string cad;
	while (cin>>cad){
		int n;
		vector<string> res;

		cin>>n;
		string p;
		for(int i = 0; i < n; i++){
			cin>>p;
			if (match(cad, p))
				res.push_back(p);
		}
		cout<<res.size()<<endl;
		for (int i = 0;i < res.size(); i++)
			cout<<res[i]<<endl;
	}
}