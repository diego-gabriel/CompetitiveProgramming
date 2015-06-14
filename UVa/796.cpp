#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define DFS_WHITE 0
vector <vector<int> > grafo;
int dfs_number_counter, dfs_root, rootChildren;
vector <int> dfs_num, dfs_low, dfs_parent;
vector <bool> articulation_vertex;

set <pair<int, int> > res;

set <pair<int, int> > :: iterator it; 

void bridges(int u){
	dfs_low[u] = dfs_num[u] = dfs_number_counter++;
	for (int j = 0; j < grafo[u].size(); j++){
		int v = grafo[u][j];
		if (dfs_num[v] == DFS_WHITE){
			dfs_parent[v] = u;
			if (u == dfs_root) rootChildren++;

			bridges(v);
			if (dfs_low[v] > dfs_num[u])
				res.insert(make_pair(min(v, u), max(v, u)));
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else
			if (v != dfs_parent[u])
				dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main(){
	int n;

	while (scanf("%d", &n) == 1){
		int origen, destino;
		vector <int> aux;
		grafo.assign(n, aux);
		res.clear();
		for (int i = 0 ; i < n; i++){
			int cLinks;

			scanf("%d (%d) ", &origen, &cLinks);
			for (int j = 0; j < cLinks; j++){
				scanf("%d", &destino);
				grafo[origen].push_back(destino);
			}
		}
		dfs_number_counter = 0;
		dfs_num.assign(n, DFS_WHITE);
		dfs_low.assign(n, 0);
		dfs_parent.assign(n, 0);
		articulation_vertex.assign(n, 0);
		int V = n;
		for (int i = 0; i < V; i++){
			if (dfs_num[i] == DFS_WHITE){
				dfs_root = i;
				rootChildren = 0;
				bridges(i);
				articulation_vertex[dfs_root] = (rootChildren > 1);
			}
		}

		printf("%d critical links\n", res.size());
		for (it = res.begin(); it != res.end(); it++){
			pair<int, int> p = *it;
			printf("%d - %d\n", (int)p.first, (int)p.second);
		}
		cout<<endl;
	}
}