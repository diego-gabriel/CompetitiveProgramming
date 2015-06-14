#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

map <int, vector <int> > grafo;
map <int, bool> visitado;

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

void dfs(int origen, stack <int> &res)
{
	visitado[origen] = true;
	for(int i = 0; i < grafo[origen].size(); i++)
	{
		if (!visitado[grafo[origen][i]])
			dfs(grafo[origen][i], res);
	}
	res.push(origen);

}

stack <int> topologicalSort()
{
	stack <int> res;

	map <int, vector <int> > :: iterator it = grafo.begin();

	while (it != grafo.end())
	{
		if (!visitado[it->first])
		{
			dfs(it->first, res);
		}

		it++;
	}

	return res;
}
int main()
{
	grafo.clear();
	visitado.clear();

	llenarGrafo();

	stack <int> res = topologicalSort();

	while (!res.empty())
	{
		cout<<res.top()<<" ";
		res.pop();
	}
	cout<<endl;

	return 0;
}