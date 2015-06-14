#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

map <int, vector <int> > grafo;
map <int, bool> vis;
map <int, int> dist;

int bfs(int origen)
{
	int res = 0;

	dist.clear();
	vis.clear();

	int destino;
	queue <int> cola;
	vector <int> vecinos;

	cola.push(origen);
	vis[origen] = true;
	dist[origen] = 0;

	while (!cola.empty())
	{
		res = origen = cola.front();
		cola.pop();
		vecinos = grafo[origen];

		for (int i = 0; i < vecinos.size(); i++)
		{
			destino = vecinos.at(i);

			if (!vis[destino])
			{
				cout<<"entraAAAAA"<<endl;
				dist[destino] = dist[origen] + 1;
				vis[destino] = true;
				cola.push(destino);
			}
		}
	}

	return res;
}

int main()
{
	int nNodes;
	while (cin>>nNodes)
	{
		grafo.clear();
		vis.clear();

		int origen, destino;
		int root;

		for (int i = 1; i < nNodes; i++)
		{
			cin>>origen>>destino;
			grafo[origen].push_back(destino);
			grafo[destino].push_back(origen);
		}

		int res = 0;

		res = dist[bfs(bfs(1))];

		cout<<res<<endl;

	}
	return 0;
}