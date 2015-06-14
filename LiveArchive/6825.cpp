#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

map <int, map<int, bool> > solved;	
vector <int> nOfCandies;
vector <vector<int> > graph;
vector <bool> visited;
set<int> res;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

void dfs(int node, int k){
	if (!solved[node][k]){
		solved[node][k] = true;
		res.insert(k);
		for (int i = 0; i < graph[node].size(); i++){
			int destino = graph[node][i];

			dfs(destino, gcd(k, nOfCandies[destino]));
		}
	}
}

int main(){

	int n, s;

	while (cin>>n>>s){
		solved.clear();
		nOfCandies.clear();
		graph.clear();
		visited.clear();
		res.clear();
		visited.assign(n+1, false);
		graph.assign(n+1, vector<int>());
		nOfCandies = vector <int>(n+1);

		for (int k = 0; k < n; k++){
			cin>>nOfCandies[k+1];
		}
		int o, d;
		for (int i = 0; i < s; i++){
			cin>>o>>d;
			graph[o].push_back(d);
			graph[d].push_back(o);
		}

		for (int origen = 1; origen <= n; origen++){
			if (!visited[origen])
				dfs(origen, nOfCandies[origen]);
		}
		cout<<res.size()<<endl;
	}

	return 0;
}