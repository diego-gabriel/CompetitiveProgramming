#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

#define MAX 1000000
#define GRAFO map <int, vector <pair <int, int> > >

int parent[MAX];

int find_parent(int a)
{
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
}

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

	void print()
	{
		cout<<"De "<<origen<<" a "<<destino<<" peso: "<<peso<<endl;
	}


};

bool operator < (const Arista &a, const Arista b)
{
	return a.peso < b.peso;
}

int main()
{
	memset(parent, -1, sizeof(parent));

	GRAFO grafo;
	int nAristas;

	cin>>nAristas;

	Arista aristas[nAristas];
	int origen, destino, peso;
	set <int> nodos;

	for (int i = 0; i < nAristas; i++)
	{
		cin>>origen>>destino>>peso;
		aristas[i] = Arista(origen, destino, peso);
		grafo[origen].push_back(make_pair(destino, peso));
		grafo[destino].push_back(make_pair(origen, peso));

		nodos.insert(origen);
		nodos.insert(destino);
	}

	vector <Arista> minimumSpanningTree;
	set <int> selectedNodes;
	set <int> :: iterator it;

	selectedNodes.insert(*nodos.begin());
	nodos.erase(nodos.begin());

	while (!nodos.empty())
	{
		Arista best;
		best.peso = 0x7fffffff;
	
		for (it = selectedNodes.begin(); it != selectedNodes.end(); it++)
		{
			vector <pair <int, int> > vecinos = grafo[*it];
		
			for (int i = 0; i < vecinos.size(); i++)
			{
				if (vecinos[i].second < best.peso && selectedNodes.find(vecinos[i].first) == selectedNodes.end())
				{	
					best = Arista(*it, vecinos[i].first, vecinos[i].second);
				}
			}
		}

		nodos.erase(best.destino);
		selectedNodes.insert(best.destino);
		minimumSpanningTree.push_back(best);
	}

	int sumTotal = 0;

	for (int i = 0; i < minimumSpanningTree.size(); i++)
	{
		sumTotal += minimumSpanningTree[i].peso;
		minimumSpanningTree[i].print();
	}

	cout<<"Peso total: "<<sumTotal<<endl;

	return 0;
}