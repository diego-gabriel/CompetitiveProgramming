#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int parent[200000 + 1];

int find_parent(int a)
{
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
}

struct Arista
{
	int origen, destino;
	int peso;

	Arista(){}

	Arista (int a, int b, int c)
	{
		origen = a;
		destino = b;
		peso = c;
	}
};

bool orden (Arista a, Arista b)
{
	return a.peso < b.peso;
}

void init (int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
}

int main()
{
	int origen, destino, peso, nAristas, nNodos;

	while (cin>>nNodos>>nAristas && (nNodos || nAristas))
	{
		init(nNodos);
		vector <Arista> aristas;
		int sumaTot;
		int sumaAct;

		sumaAct = sumaTot = 0;

		for (int i = 0; i < nAristas; i++)
		{
			cin>>origen>>destino>>peso;
			aristas.push_back(Arista(origen, destino, peso));
			sumaTot += peso;
		}

		int inNodes = 1;

		sort(aristas.begin(), aristas.end(), orden);

		for (int i = 0; i < aristas.size(); i++)
		{
			origen = aristas[i].origen;
			destino = aristas[i].destino;

			int parA = find_parent(origen);
			int parB = find_parent(destino);

			if (parA != parB)
			{
				inNodes++;

				parent[parA] = parB;
				sumaAct += aristas[i].peso;
			}
		}

		cout<<sumaTot - sumaAct<<endl;

	}
	return 0;
}