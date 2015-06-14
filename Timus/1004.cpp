#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define MAX 0x0fffffff

struct Arista
{
	int to;
	int weight;

	Arista(){
	}
	Arista(int a, int b){
		to = a;
		weight = b;
	}
};

bool operator < (Arista a, Arista b){
	if (a.weight == b.weight)
		return a.to < b.to;
	return a.weight < b.weight;
}

int n, m;
int dist[110];
bool able[100][100];
int peso[110][110];
int parent[110];
int best;
vector<vector<int> > g;
stack<int> res;

void reset(){
	for(int i = 0; i <= n; i++){
		dist[i] = MAX;
		parent[i] = i;
	}
}
void init(){
	memset(able, true, sizeof(able));
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			peso[i][j] = MAX;
}

int dijkstra(int origen, int destino){
	reset();
	priority_queue<Arista> cola;
	dist[origen] = peso[origen][destino];
	cola.push(Arista(origen, 0));
	int p, d, o;
	while(!cola.empty()){
		o = cola.top().to;
		p = cola.top().weight;
		cola.pop();

		if (p >= best)
			break;

		//cout<<"actually on: "<<o<<endl;
		for(int i = 0, n = g[o].size(); i < n; i++){
			d = g[o][i];
			//cout<<"	next: "<<d<<endl;
			if (!able[o][d]){
				//cout<<"disabled "<<o<<" -> "<<d<<endl;
				continue;
			} 
			if(dist[o] + peso[o][d] < dist[d]){
				parent[d] = o;
				dist[d] = dist[o] + peso[o][d];
				cola.push(Arista(d, dist[d]));
			}
		}
	}
	//cout<<"dijkstra "<<origen<<" to "<<destino<<" returning: "<<dist[destino]<<endl;
	return dist[destino];
}

int main(){
	while(scanf("%d", &n) && n != -1){
		scanf("%d", &m);

		g.clear();
		g.assign(n+1, vector<int>());
		init();
		int o, d, p;
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &o, &d, &p);
			g[o].push_back(d);
			g[d].push_back(o);
			peso[o][d] = min(peso[o][d], p);
			peso[d][o] = min(peso[d][o], p);
		}

		best = MAX;

		for(int i = 1; i <= n; i++)
			for(int j = i+1;j <= n; j++){
				if (peso[i][j] == MAX)
					continue;
				//cout<<"DISABLING "<<i<<" to "<<j<<endl;
				able[i][j] = false;
				able[j][i] = false;

				int cicle = dijkstra(i, j);

				if (cicle < best){
					best = cicle;

					//cout<<"best>>>>>>>> "<<best<<endl;
					int node = j;
					res = stack<int>();
					while (parent[node] != node){
						res.push(node);
						node = parent[node];
					}
					res.push(node);	
				}

				able[j][i] = true;
				able[i][j] = true;
			}

		if (best != MAX){
			//cout<<"BEST> "<<best<<endl;
			printf("%d", res.top());
			res.pop();
			while (!res.empty()){
				printf(" %d", res.top());
				res.pop();
			}
			printf("\n");

		} else {
			printf("No solution.\n");
		}

	}
	return 0;
}