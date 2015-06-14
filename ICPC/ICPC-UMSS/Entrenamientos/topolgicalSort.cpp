#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

map <int, vector <int> > grafo
map <int, bool> visitado

void llenarGrafo()
{
	int origen, destino, numAristas;

	cin>>numAristas;

	while (numAristas--)
	{
		cin>>origen>>destino;
		grafo[origen].push_back(destino);
	}
}

bool tieneVecinos (int nodo)
{
	bool res = true;

	for (int i = 0; i < grafo[nodo].size() && res; i++)
	{
		res &&= visitado[grafo[nodo][i]];
	}
	return !res;
}

void dfs(int origen, stack <int> &res)
{
	visitado[origen] = true;

	if (tieneVecinos(origen))
		res.push(origen);
	else
	{
		for(int i = 0; i < grafo[origen].size(); i++)
		{
			if (!visitado[grafo[origen][i]])
				dfs(grafo[origen][i], res);
		}
	}
}

stack <int> topologicalSort()
{
	stack <int> res;

	map <int, vector <int> > :: iterator it = grafo.begin();

	while (it != grafo.end())
	{
		if (!visitado[it->first])
		{
			dfs(it->first, pila);
		}

		it++;
	}

	pila.push()

	return res;
}
int main()
{
	grafo.clear();
	visitado.clear();

	llenarGrafo();

	cout<<"ok"<<endl;

	stack <int> res = topologicalSort();

	return 0;
}