#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int parent[1000+5];

int findParent(int a){
	return parent[a] == a ? a : parent[a] = findParent(parent[a]);
}

struct Ciudad
{
	double x, y;
	int id;
	Ciudad(){};
	void read(int u){
		scanf("%lf %lf", &x, &y);
		id = u;
	}
};

struct Arista
{
	int origen, destino;
	double peso;

	Arista(){};
	Arista(Ciudad a, Ciudad b){
		origen = a.id;
		destino = b.id;
		peso = sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
	}
};

bool orden(Arista a, Arista b){
	return a.peso < b.peso;
}

int main(){
	int nTest;

	scanf("%d", &nTest);

	for (int test = 0; test < nTest; test++){
		int n, m;
		scanf("%d", &n);
		Ciudad ciudad[n];
		for (int i = 0; i < n; i++){
			ciudad[i].read(i);
			parent[i] = i;
		}
		vector <Arista> aristas;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				aristas.push_back(Arista(ciudad[i], ciudad[j]));
			}
		}
		scanf("%d", &m);
		int origen, destino;
		int p1, p2;
		n--;
		for (int i = 0; i < m; i++){
			scanf("%d %d", &origen, &destino);
			p1 = findParent(origen-1);
			p2 = findParent(destino-1);
			if (p1 != p2){
				parent[p1] = p2;
				n--;
			}	
		}

		double res = 0.0;
		sort(aristas.begin(), aristas.end(), orden);
		int i = 0;
		while (n){
			origen = aristas[i].origen;
			destino = aristas[i].destino;

			p1 = findParent(origen);
			p2 = findParent(destino);

			if (p1 != p2){
				res = max(res, aristas[i].peso);
				parent[p1] = p2;
				n--;
			}

			i++;
		}
		printf("Caso %d: %lld\n", test+1, (long long)res);
	}
	return 0;
}