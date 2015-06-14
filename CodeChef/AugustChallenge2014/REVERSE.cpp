#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	vector <int> in;
	vector <int> out;
	int s;
	Node(){
		s = 0x08888888; 
	};

	void addIn(int i){
		in.push_back(i);
	}

	void addOut(int i){
		out.push_back(i);
	}
};

int main(){
	int n, m;

	cin>>n>>m;

	Node graph[n+1];
	int origen, destino;
	for (int i = 0; i < m; i++){
		cin>>origen>>destino;
		graph[origen].addOut(destino);
		graph[destino].addIn(origen);
	}

	queue<int> cola;
	cola.push(n);
	graph[n].s = 0;

	while (!cola.empty()){
		int node = cola.front();
		cola.pop();

		for (int i = 0; i < graph[node].in.size(); i++){
			int d = graph[node].in.at(i);
			if (graph[d].s > graph[node].s){
				graph[d].s = graph[node].s;
				cola.push(d);
			}
		}
		for (int i = 0; i < graph[node].out.size(); i++){
			int d = graph[node].out.at(i);
			if (graph[node].s+1 < graph[d].s){
				graph[d].s = graph[node].s+1;
				cola.push(d);
			}
		}
	}

	cout<<(graph[1].s == 0x08888888 ? -1 : graph[1].s)<<endl;

}