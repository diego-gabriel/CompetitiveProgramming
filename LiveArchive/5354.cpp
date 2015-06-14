#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

map <char, vector<char> > g;
map <char, bool> vis;
bool full(string cad, char k){
	bool res = true;
	for (int i = 0; i < cad.length() && res; i++)
		res = cad[i] == k;
	return res;
}

int dfs(char k){
	int res = 1;
	vis[k] = true;

	for(int i = 0; i < g[k].size(); i++){
		if (!vis[g[k][i]])
			res += dfs(g[k][i]);
	}

	return res;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		g.clear();
		vis.clear();
		string cad;
		while(cin>>cad && !full(cad, '*')){
			g[cad[1]].push_back(cad[3]);
			g[cad[3]].push_back(cad[1]);
		}	
		cin>>cad;
		int tree = 0;
		int acorn = 0;
		for (int i = 0; i < cad.length(); i += 2){
			if (vis[cad[i]])
				continue;
			if (dfs(cad[i]) == 1)
				acorn++;
			else
				tree++;
		}

		cout<<"There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s)."<<endl;

	}
	return 0;
}