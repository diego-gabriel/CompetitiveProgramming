#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

unsigned long long dist[1001][1001];
struct Arista
{
	unsigned long long destino, peso;
	Arista(){};
	Arista(unsigned long long a, unsigned long long b){
		destino = a;
		peso = b;
	}
};

bool operator < (Arista a, Arista b){
	if (a.peso == b.peso)
		return a.destino < b.destino;
	return a.peso < b.peso;
}

vector <vector<Arista> > grafo;
void dijkstra(int ini){
	int origen, destino, peso;
	set<Arista> cola;
	origen = ini;
	dist[ini][origen] = 0;
	cola.insert(Arista(origen, 0));
	Arista arista;

	while (!cola.empty()){
		arista = *(cola.begin());
		cola.erase(cola.begin());
		origen = arista.destino;

		for (int i = 0; i < grafo[origen].size(); i++){
			destino = grafo[origen][i].destino;
			peso = grafo[origen][i].peso;

			if (dist[ini][destino] > dist[ini][origen]+peso){
				dist[ini][destino] = dist[ini][origen]+peso;
				cola.insert(Arista(destino, dist[ini][destino]));
			}
		}
	}

}

void print(int n){
	for (int i = 1; i <= n; i++){
		for(int j =1; j <= n; j++){
			cout<<" ";
			if (dist[i][j] == 0xffffffffffffffff)
				cout<<"x";
			else
				cout<<dist[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){

	int n, m;
	cin>>n>>m;
	memset(dist, 0xff, sizeof(dist));
	//cout<<dist[1][1]<<endl;
	grafo.assign(n+1, vector<Arista>());
	int inicio, fin;
	cin>>inicio>>fin;
	int origen, destino , peso;
	for (int i = 0; i < m; i++){
		cin>>origen>>destino>>peso;
		grafo[origen].push_back(Arista(destino, peso));
		grafo[destino].push_back(Arista(origen, peso));
	}

	for (int i = 1; i <= n; i++){
		dijkstra(i);
	}

	//print(n);

	grafo.clear();
	grafo.assign(n+1, vector<Arista>());
	int distancia, costo;
	for (int i = 1; i <= n; i++){

		cin>>distancia>>costo;
		for (int j = 1; j <= n; j++)
			if (dist[i][j] <= distancia){
				grafo[i].push_back(Arista(j, costo));
			}
	}


	memset(dist, 0xff, sizeof(dist));
	dijkstra(inicio);
	//print(n);

	if (dist[inicio][fin] != 0xffffffffffffffff)
		cout<<dist[inicio][fin]<<endl;
	else
		cout<<-1<<endl;
	

	return 0;
}