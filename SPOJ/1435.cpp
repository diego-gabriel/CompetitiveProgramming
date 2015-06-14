#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 100000+1
queue <int> topoSort;
map <int, vector<int> > arbol;
int parent[MAX];
bool vis[MAX];
bool sol[MAX];

void dfs(int x){
	vis[x] = true;
	for (int i = 0; i < arbol[x].size(); i++){
		if (!vis[arbol[x][i]]){
			parent[arbol[x][i]] = x;
			dfs(arbol[x][i]);
		}
	}
	topoSort.push(x);
}

int main(){
	int n;
	int res = 0;
	cin>>n;
	if (n == 1){
		cout<<0<<endl;
		return 0;
	}
	int o, d;
	for (int i = 0; i < n-1; i++){
		cin>>o>>d;
		arbol[o].push_back(d);
		arbol[d].push_back(o);
	}
	memset(vis, false, sizeof(vis));
	parent[1] = 1;
	dfs(1);
	memset(vis, false, sizeof(vis));
	memset(sol, false, sizeof(sol));
	int node;
	while (!topoSort.empty()){
		node = topoSort.front();
		topoSort.pop();
		if (node == 1 && !vis[node]){
			bool b = false;
			for (int i = 0; i < arbol[1].size() && !b; i++){
				b = b || sol[arbol[1][i]];
			}
			if (!b)
				res++;
		}
		else
		if (!vis[node] && !vis[parent[node]]){
			res++;
			vis[node] = true;
			vis[parent[node]] = true;
			sol[parent[node]] = true;
		}
	}


	cout<<res<<endl;
}