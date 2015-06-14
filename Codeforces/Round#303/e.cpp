#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	long long to;
	long long w;

	Edge(){};
	Edge(long long a, long long b){
		to = a;
		w = b;
	}
};

bool operator < (Edge a, Edge b){
	if (a.w == b.w)
		return a.to < b.to;
	return a.w < b.w;
}

int main(){

	long long n, m;
	cin>>n>>m;
	vector <map<long long, long long> > graph;
	vector <map<int, int> > idEdge;
	vector <long long > dist;
	map <long long, long long> :: iterator it;
	long long parent[n+1];
	long long INF = 0x7fffffffffffffff;

	//set variables
	dist.assign(n+1, INF);
	graph.assign(n+1, map<long long, long long>());
	idEdge.assign(n+1, map<int, int>());

	for (int i = 0; i <= n; i++){
		parent[i] = i;
	}

	long long origen, destino, peso;
	
	//build Graph
	for (int i = 0; i < m ;i++){
		cin>>origen>>destino>>peso;
		graph[origen][destino] = peso;
		graph[destino][origen] = peso;
		idEdge[origen][destino] = i+1;
		idEdge[destino][origen] = i+1;
	}
	cin>>origen;
	long long oooo = origen;
	long long tot = 0;
	//dijsktra
	dist[origen] = 0;
	set<Edge> cola;
	cola.insert(Edge(origen, 0));
	Edge source, target;
	while (!cola.empty()){
		source = *(cola.begin());

		cola.erase(cola.begin());

		origen = source.to;

		for (it = graph[origen].begin(); it != graph[origen].end(); it++){
			destino = it->first;
			peso = it->second;

			long long newTot = tot;

			newTot += peso;
			if (parent[destino] != destino){
				newTot -= graph[destino][parent[destino]];
			}

			if (dist[destino] > dist[origen]+peso || (dist[destino] == dist[origen]+peso && newTot < tot)){
				dist[destino] = dist[origen]+peso;
				cola.insert(Edge(destino, dist[destino]));
				tot = newTot;

				parent[destino] = origen;

			}
		}

	}

	set<int> res;
	set<int> :: iterator tt;
	tot = 0;
	for (int i = 0; i < n+1; i++){
		if (parent[i] != i){
			tot += graph[i][parent[i]];
			res.insert(idEdge[i][parent[i]]);
		}
	}

	cout<<tot<<endl;
	for (tt = res.begin(); tt != res.end(); tt++){
		if (tt != res.begin())
			cout<<" ";
		cout<<*tt;
	}
	cout<<endl;

	return 0;
}