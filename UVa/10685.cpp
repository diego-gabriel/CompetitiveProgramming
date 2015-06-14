#include <iostream>
#include <map>
#include <cstring>

using namespace std;

map <string, string> parent;

string find_parent(string a){
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
}

void init(int n){
	parent.clear();
	string name;

	for (int i = 0; i < n; i++){
		cin>>name;
		parent[name] = name;
	}
}

int max(int a, int b){
	return a < b ? b : a;
}

int main(){
	int c, r;
	while (cin>>c>>r && (c || r)){
		init(c);
		string predator, presa;
		for (int i = 0; i < r; i++){
			cin>>predator>>presa;
			parent[find_parent(presa)] = find_parent(predator);
		}

		map <string, int> count;
		map <string, string> :: iterator it;
		int res = 0;

		for (it = parent.begin(); it != parent.end(); it++){
			string par = find_parent(it->first);
			count[par]++;
			res = max(res, count[par]);
		}
		cout<<res<<endl;
	}
	return 0;
}