#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>


using namespace std;

struct Arista
{
	long long destino, peso;
	Arista(){};
	Arista(long long a, long long b){
		destino = a;
		peso = b;
	}
};

bool operator < (Arista a, Arista b){
	if (a.peso == b.peso)
		return a.destino < b.destino;
	return a.peso < b.peso;
}

int main(){
	long long n, origen, destino;
	long long max = 0xffffffff;
	cin>>n>>origen>>destino;

	vector <vector<Arista> > g;
	g.assign(n, vector<Arista>());
	long long peso;
	for (long long i = 0; i < n; i++){
		for (long long j = 0; j < n; j++){
			cin>>peso;
			if (peso > 0 && peso <= 10000){
				g[i].push_back(Arista(j, peso));
			}
		}
	}

	vector<long long> dist;
	dist.assign(n, max);
	set<Arista> cola;
	cola.insert(Arista(origen-1, 0));
	dist[origen-1] = 0;
	long long d, p;
	Arista o;

	while (!cola.empty()){
		o = *(cola.begin());
		cola.erase(cola.begin());
		for (long long i = 0; i < g[o.destino].size(); i++){
			d = g[o.destino][i].destino;
			p = g[o.destino][i].peso;
			if (dist[o.destino]+p < dist[d]){
				cola.insert(Arista(d, dist[o.destino]+p));
				dist[d] = dist[o.destino]+p;
			}
		}
	}
	if (dist[destino-1] != max)
		cout<<dist[destino-1]<<endl;
	else
		cout<<-1<<endl;

	return 0;
}