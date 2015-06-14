#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define INF 0x7fffffff

struct Arista
{
	int origen;
	int destino;
	int peso;

	Arista(){}
	Arista(int a, int b, int c)
	{
		origen = a;
		destino = b; 
		peso = c;
	}
};

int main()
{
	int nAristas, nNodos, origen, destino, peso;

	cin>>nAristas>>nNodos; 
	int distancia[nNodos+1];
	Arista aristas[nAristas];

	map <int, int> parent;

	for (int i = 0; i < nAristas; i++)
	{
		cin>>origen>>destino>>peso;
		aristas[i] = Arista(origen, destino, peso);
		distancia[origen] = distancia[destino] = INF;
	}

	int dist, destFinal;

	cin>>origen>>destFinal;
	cout<<origen<<" "<<destFinal<<endl;

	//Bellman-Ford

	distancia[origen] = 0;
	parent[origen] = origen;

	for (int j = 0; j < nNodos-1; j++)
	{
		for (int i = 0; i < nAristas; i++)
		{
			origen = aristas[i].origen;
			destino = aristas[i].destino;

			dist = distancia[origen] + aristas[i].peso;

			if (distancia[destino] > dist)
			{
				cout<<"era: "<<distancia[destino]<<endl;
				distancia[destino] = dist;
				parent[destino] = origen;

				cout<<destino<<" desde "<<origen<<" es: "<<distancia[destino]<<endl;
			}
		}
	}

	bool cicloNeg = false;

	for (int i = 0; i < nAristas && !cicloNeg; i++)
	{
		origen = aristas[i].origen;
		destino = aristas[i].destino;

		dist = distancia[origen] + aristas[i].peso;

		cicloNeg = dist < distancia[destino];
	}

	if (cicloNeg) cout<<"cicloNeg"<<endl;

	else{
		for (int i = 1; i <= nNodos; i++)
		cout<<"la distancia mas corta a " << i <<" es: "<<distancia[i]<<endl;
}

	cout<<destFinal<<endl;
	while (parent[destFinal] != destFinal)
	{
		cout<<parent[destFinal]<<", ";
		destFinal = parent[destFinal];
	}
	cout<<endl;

	return 0;
}