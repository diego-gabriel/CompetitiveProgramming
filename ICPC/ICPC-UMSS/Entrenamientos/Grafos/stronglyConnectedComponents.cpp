#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

#define GRAFO map <int, vector <int> >

struct Component
{
	vector <int> nodes;

	Component(){}

	void add(int a)
	{
		nodes.push_back(a);
	}

	void print()
	{
		for (int i = 0; i < nodes.size(); i++)
			cout<<nodes[i]<<" ";
		cout<<endl;
	}

	void clear()
	{
		nodes.clear();
	}
};

void llenarGrafo (GRAFO &grafo)
{
	int origen, destino, numAristas;

	cin>>numAristas;

	while (numAristas--)
	{
		cin>>origen>>destino;
		grafo[origen].push_back(destino);
	}
}

void dfsTrans(int origen, GRAFO &grafo, GRAFO &res, map <int, bool> &visitado, stack <int> &pila)
{
	int destino;

	visitado[origen] = true;

	for (int i = 0; i < grafo[origen].size(); i++)
	{
		destino = grafo[origen][i];
		res[destino].push_back(origen);

		if (!visitado[destino])
			dfsTrans(destino, grafo, res, visitado, pila);
	}

	pila.push(origen);
}

GRAFO transponer(GRAFO &grafo, stack <int> &pila)
{
	GRAFO res;

	GRAFO :: iterator it = grafo.begin();

	map <int, bool> visitado;

	while (it != grafo.end())
	{
		if (!visitado[it->first])
			dfsTrans(it->first, grafo, res, visitado, pila);

		it++;
	}

	return res;
}

void dfs(int origen, GRAFO &grafo, map <int, bool> &visitado, Component &c)
{
	int destino;

	visitado[origen] = true;
	c.add(origen);

	for (int i = 0; i < grafo[origen].size(); i++)
	{
		destino = grafo[origen][i];

		if (!visitado[destino])
			dfs(destino, grafo, visitado, c);
	}

}


vector <Component> findComponents (GRAFO grafo)
{
	stack <int> pila;
	GRAFO grafoT = transponer(grafo, pila);

	Component component;
	vector <Component> res;
	map <int, bool> visitado;

	while (!pila.empty())
	{
		int origen = pila.top();
		pila.pop();

		if (!visitado[origen])
		{
			dfs(origen, grafoT, visitado, component);

			res.push_back(component);
			component.clear();
		}
	}

	return res;
}


int main()
{
	GRAFO grafo;

	llenarGrafo(grafo);
	vector <Component> res = findComponents(grafo);

	for (int i = 0; i < res.size(); i++)
		res[i].print();

	return 0;
}