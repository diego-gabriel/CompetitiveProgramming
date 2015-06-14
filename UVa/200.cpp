#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>

using namespace std;

map <char, vector <char> > grafo;
map <char, bool> visitado;
set <char> nodos;

void include (string cad, map <char, vector <string> > &mapa)
{
	if (cad.length() >= 2)
		mapa[cad[0]].push_back(cad.substr(1));
}

void makeGraph(vector <string>  &cadSet)
{
	if (cadSet.size() < 2) return;

	vector <string> :: iterator o, d;
	char origen, destino;

	map <char, vector <string> > sets;
	map <char, vector <string> > :: iterator it;

	o = d = cadSet.begin();
	d++;

	include(*o, sets);

	while (d != cadSet.end())
	{

		origen = o -> at(0);
		destino = d -> at (0);

		if (origen != destino)
			grafo[origen].push_back(destino);

		include(*d, sets);

		o++;
		d++;
	}

	for (it = sets.begin(); it != sets.end(); it++)
	{
		if ((it -> second).size() > 1)
			makeGraph(it -> second);
	}
}

void prinfGraph()
{
	map <char, vector <char> > :: iterator it;

	for (it = grafo.begin(); it != grafo.end(); it++)
	{
		vector <char> vec = it -> second;
		cout<<it -> first<<": "<<endl;
		for (int i = 0; i < vec.size(); i++)
		{
			cout<<vec[i]<<" ";
		}
		cout<<endl<<endl;
	}
}

void dfs(char origen, stack <char> &pila)
{
	char destino;
	vector <char> vecinos = grafo[origen];

	visitado[origen] = true;

	for(int i = 0; i < vecinos.size(); i++)
	{
		destino = vecinos[i];
		if (!visitado[destino])
			dfs(destino, pila);
	}

	pila.push(origen);
}

stack <char> topologicalSort()
{
	stack <char> res;

	set <char> :: iterator it;

	for (it = nodos.begin(); it != nodos.end(); it++)
	{
		if (!visitado[*it])
			dfs(*it, res);
	}

	return res;
}


int main()
{
 	string cad;

 	vector <string>  cadenas;

 	while (cin>>cad && cad[0] != '#')
 	{
 		cadenas.push_back(cad);
 		for (int i = 0; i < cad.length(); i++)
 			nodos.insert(cad[i]);
 	}

 	if (cadenas.size() > 1)
 	{
 		grafo.clear();
 		makeGraph(cadenas);

 		stack <char> res = topologicalSort();

 		while (!res.empty())
 		{
 			cout<<res.top();
 			res.pop();
 		}
 		cout<<endl;

 	}
 	else
 		cout<<(*cadenas.begin())[0]<<endl;

	return 0;
}