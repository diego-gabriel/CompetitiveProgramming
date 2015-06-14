#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int to[50000+5];
int memo[50000+5];
bool visited[50000+5];
set <int> stacked;
int cycleStartsOn;

bool isStacked(int node){
	return stacked.find(node) != stacked.end();
}

int dfs(int node, int iteration){
	
	if (!visited[node]){
		memo[node] = iteration;
		visited[node] = true;
		stacked.insert(node);

		int next = to[node];

		if (isStacked(next)){
			cycleStartsOn = next;
			memo[node] = iteration - memo[next] + 1;
		} else {
			
			memo[node] = dfs(next, iteration+1)+1;
			if (cycleStartsOn != 0){
				memo[node] = memo[next];
				if (node == cycleStartsOn) 
					cycleStartsOn = 0;
			}
		}
	}

	return memo[node];
}


int main(){
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		int n;
		cin>>n;
		int u, v;
		for (int i = 0; i < n; i++){
			cin>>u>>v;
			to[u] = v;
		}

		memset(visited, false, sizeof(visited));
		memset(memo, 0, sizeof(memo));
		int res = 0;
		int maxCycle = 0;
		for (int node = 1; node <= n; node++){
			if (!visited[node]){
				stacked.clear();
				cycleStartsOn = 0;
				int aux = dfs(node, 1);
				if (aux > maxCycle){
					maxCycle = aux;
					res = node;
				}
			}
		}

		printf("Case %d: %d\n", test, res);

	}
	return 0;
}