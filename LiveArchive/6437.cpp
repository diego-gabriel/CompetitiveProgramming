#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int parent[300];

void init(){
	for (int i = 0; i < 300; i++){
		parent[i] = i;
	}
}

int find_parent(int a){
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
}

struct Arista
{
	int origen, destino, peso;
	Arista(){};
	Arista(bool a){
		cin>>origen>>destino>>peso;
	}
};

bool orden (Arista a, Arista b){
	return a.peso < b.peso;
}

int main(){
	int nTest;
	cin>>nTest;
	for(int test = 1; test <= nTest; test++){
		int n, m, k;
		cin>>n>>m>>k;
		init();
		int pp, pa;
		cin>>pp;
		for (int i = 1; i < k; i++){
			cin>>pa;
			parent[pa] = parent[pp];
		}
		vector <Arista> aristas;
		for (int i = 0; i < m; i++){
			aristas.push_back(Arista(true));
		}
		sort(aristas.begin(), aristas.end(), orden);

		int res = 0;
		for (int i = 0; i < aristas.size(); i++){
			Arista arista = aristas.at(i);
			int parentA = find_parent(arista.origen);
			int parentB = find_parent(arista.destino);

			if (parentA != parentB){
				res += arista.peso;
				parent[parentA] = parentB;
			}
		}

		cout<<"Case #"<<test<<": "<<res<<endl;
	}
	return 0;
}