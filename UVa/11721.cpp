#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;

vector <vector <pair <int, int> > > grafo, grafoT;
stack <int> topo;
vector <bool> vis, cVis;
vector <bool> onNegCy, compOn;
vector <int> dist, belongsTo;
vector <vector<int> > components;
vector <set<int> > grafoC;
int n, m;

void leerGrafo(){
	int origen, destino, peso;
	for (int i = 0; i < m; i++){
		cin>>origen>>destino>>peso;

		grafo[origen].push_back(make_pair(destino, peso));
		grafoT[destino].push_back(make_pair(origen, peso));
	}
}

void topoDfs(int vertex){
	vis[vertex] = true;

	for (int i = 0; i < grafo[vertex].size();i++){
		if (!vis[grafo[vertex][i].first])
			topoDfs(grafo[vertex][i].first);
	}
	topo.push(vertex);
}

void dfsComp(int origen, vector<int> &component, int &componentID){
	belongsTo[origen] = componentID;
	vis[origen] = true;
	component.push_back(origen);

	for (int i = 0; i < grafoT[origen].size(); i++){
		if (!vis[grafoT[origen][i].first]){
			dfsComp(grafoT[origen][i].first, component, componentID);
		}
	}
}

void findComponents(){
	vis.assign(n, false);

	for (int i = 0; i < n; i++){
		if (!vis[i]){
			topoDfs(i);
		}
	}
	
	vector <int> component;
	belongsTo.assign(n, 0);
	int componentID = 0;
	int origen;
	vis.assign(n, false);
	while (!topo.empty()){
		origen = topo.top();
		topo.pop();
		if (!vis[origen]){

			component.clear();
			dfsComp(origen, component, componentID);
			componentID++;
			components.push_back(component);
		}
	}

	grafoC.assign(components.size(), set<int>());
	for (int i = 0; i < n; i++){
		for (int j = 0; j < grafo[i].size(); j++){
			if (belongsTo[i] != belongsTo[grafo[i][j].first]){
				grafoC[belongsTo[grafo[i][j].first]].insert(belongsTo[i]);

			}
		}
	}

}

void bellmanFord(vector <int> &component){
	int origen, destino, peso;

	dist[component[0]] = 0;

	for (int t = 0; t < component.size()-1; t++){
		for (int i = 0; i < component.size(); i++){
			origen  = component[i];
			for (int j = 0; j < grafo[origen].size(); j++){
				destino = grafo[origen][j].first;
				peso = grafo[origen][j].second;

				if ((dist[destino] > dist[origen] + peso) && belongsTo[destino] == belongsTo[origen]){
					dist[destino] = dist[origen] + peso;
				}
			}
		}
	}
	bool negCycle = false;
	for (int i = 0; i < component.size() && !negCycle; i++){
		origen = component[i];
		for (int j = 0; j < grafo[origen].size() && !negCycle; j++){
			destino = grafo[origen][j].first;
			peso = grafo[origen][j].second;
			negCycle = (dist[destino] > dist[origen] + peso) && belongsTo[destino] == belongsTo[origen];
		}
	}
	if (negCycle){

		for(int i = 0; i < component.size(); i++){
			onNegCy[component[i]] = true;
		}
		compOn[belongsTo[component[0]]] = true;
	}
}

void dfsAssignComp(int compID){
	cVis[compID] = true;
	set<int> :: iterator it;
	for (it = grafoC[compID].begin(); it != grafoC[compID].end(); it++){
		if (!cVis[*it]){
			dfsAssignComp(*it);
		}
	}

	if (!compOn[compID]){
		for (int i = 0; i < components[compID].size(); i++){
			onNegCy[components[compID][i]] = true;
		}
		compOn[compID] = true;
	}
}

int main(){
	int t;
	scanf("%d", &t);

	for (int test = 1; test <= t; test++){
		cin>>n>>m;
		n += 10;
		grafo.assign(n, vector<pair<int, int> >());
		grafoT.assign(n, vector<pair<int, int> >());
		int origen, destino, peso;
		components.clear();

		leerGrafo();

		findComponents();

		dist.assign(n, 0x0fffffff);
		onNegCy.assign(n, false);
		compOn.assign(components.size(), false);
		
		for (int i = 0; i < components.size(); i++){
			bellmanFord(components[i]);
			if (compOn[i]){
				cVis.assign(components.size(), false);
				dfsAssignComp(i);
			}
		}
		
		bool atLeastOne = false;
		printf("Case %d:", test);
		for (int i = 0; i < n-10; i++){
			if (onNegCy[i]){
				printf(" %d", i);
				atLeastOne = true;
			}
		}

		if (!atLeastOne)
			printf(" impossible");
		printf("\n");
	}
}