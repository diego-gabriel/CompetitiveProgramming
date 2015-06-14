#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define INF 0x7fffffff


int main()
{
	map <int, vector <pair <int, int> > > grafo;
	map <int, int> distancia;
	map <int, int> parent;
	int nAristas;
	int origen, destino, peso;

	cin>>nAristas;

	for (int i = 0; i < nAristas; i++)
	{
		cin>>origen>>destino>>peso;
		grafo[origen].push_back(make_pair(destino, peso));

		distancia[origen] = distancia[destino] = INF;
	}

	int destinoFinal;
	cin>>origen>>destinoFinal;

	queue <int> cola;
	distancia[origen] = 0;

	parent[origen] = origen;

	cola.push(origen);

	while (!cola.empty())
	{
		origen = cola.front();
		vector <pair <int, int> > vecinos = grafo[origen];
		cola.pop();

		for (int i = 0; i < vecinos.size(); i++)
		{
			int nDist = distancia[origen] + vecinos[i].second;
			destino = vecinos[i].first;

			if (distancia[destino] > nDist)
			{
				distancia[destino] = nDist;

				parent[destino] = origen;

				cola.push(destino);
			}
		}

	}

	cout<<"La distancia mas corta es: "<<distancia[destinoFinal]<<endl;

	while (parent[destinoFinal] != destinoFinal)
	{
		cout<<parent[destinoFinal]<<", ";
		destinoFinal = parent[destinoFinal];
	}


	return 0;
}