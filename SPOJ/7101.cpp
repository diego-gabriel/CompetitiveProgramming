#include <iostream> 
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
#include <stack>

using namespace std;

#define MAX 0x0fffffff
struct Arista
{
	int destino, peso;
	Arista(){destino = peso = 0;}
	Arista (int a, int b){
		destino = a;
		peso = b;
	}
};

bool operator < (Arista x, Arista a){
	if (x.peso == a.peso){
		return x.destino < a.destino;
	}
	return x.peso < a.peso;
}
void print(vector <int> v){
	for (int i = 0; i < v.size(); i++)
		cout<<" "<<v[i];
	cout<<endl;
}

void dijkstra(int origen, vector<int> &dist, vector <vector<Arista> > &grafo){
		int destino, peso;
		set <Arista> cola;
		dist[origen] = 0;
		cola.insert(Arista(origen, 0));
		Arista arista;

		while (!cola.empty()){
			arista = *(cola.begin());
			cola.erase(cola.begin());
			origen = arista.destino;
			vector <Arista> vecinos = grafo[origen];
			//cout<<"Origen: "<<origen<<" -> Peso: "<<arista.peso<<" cant de vecinos: "<<vecinos.size()<<endl;
			for (int i = 0; i < vecinos.size(); i++){
				peso = vecinos[i].peso;
				destino = vecinos[i].destino;
			//	cout<<"hasta: "<<destino<<" -> "<<peso<<endl;

				if (dist[destino] > dist[origen] + peso){
					dist[destino] = dist[origen] + peso;
					cola.insert(Arista(destino, dist[destino]));
				}
			}

		}

//cout<<"dist: ";
//		print(dist);
}


int main(){
	int j, b, c, n, s;

	vector <vector <Arista> > grafo;
	while (cin>>j>>b>>c>>n>>s){
		if (j == -1 && b == -1 && c == -1 && n == -1 && s == -1)
			break;
		grafo.clear();
		vector <int> B, N, C;
		vector <Arista> aux;
		grafo.assign(j+1, aux);
		int origen, destino, peso;
		for (int i = 0; i < s; i++){
			cin>>origen>>destino>>peso;
			grafo[origen].push_back(Arista(destino, peso));
			grafo[destino].push_back(Arista(origen, peso));
		}


		B.assign(j+1, MAX);
		C.assign(j+1, MAX);
		N.assign(j+1, MAX);

		dijkstra(b, B, grafo);
		dijkstra(c, C, grafo);
		dijkstra(n, N, grafo);

		int res = -1;
		int nodo;
		for (int x = 1; x <= j; x++){
			if (B[x] + C[x] == B[c] &&
				B[x] + N[x] == B[n]){
				if (B[x] > res){
					res = B[x];
					nodo = x;
//					cout<<"found nodo "<<nodo<<endl;
				}
			}
		}
		cout<<B[nodo]<<" "<<C[nodo]<<" "<<N[nodo]<<endl;

		

	}
	return 0;
}