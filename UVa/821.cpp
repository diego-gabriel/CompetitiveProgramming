#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

map <int, vector <int> > grafo;
bool inUse[101];

double bfs(int origen)
{
	int dist[101];
	memset(dist, 0, sizeof(dist));
	bool vis[101];
	int destino;

	memset(vis, false, sizeof(vis));
	double res = 0.0;
	queue <int> cola;

	dist[origen] = 0;
	cola.push(origen);
	vis[origen] = true;

	while(!cola.empty())
	{
		origen = cola.front();
		cola.pop();

		vector <int> vecinos = grafo[origen];

		for (int i = 0; i < vecinos.size(); i++)
		{
			destino = vecinos[i];

			if (!vis[destino])
			{
				vis[destino] = true;
				dist[destino] = dist[origen] + 1;
				cola.push(destino);
			}
		}
	}

	for (int i = 1; i < 101; i++)
	{
		res += dist[i];
	}

	return res;
}

int main()
{
	int origen, destino;
	int test = 0;
	while (cin>>origen>>destino && origen && destino)
	{
		test++;
		grafo.clear();
		memset(inUse, false, sizeof(inUse));
		double res = 0.0;
		do
		{
			grafo[origen].push_back(destino);
			inUse[origen] = inUse[destino] = true;
			cin>>origen>>destino;
		} while (origen || destino);

		double nNodes = 0;
		for (int i = 1; i < 101; i++)
		{
			if (inUse[i])
			{
				nNodes += 1.0;
				res += bfs(i);
			}
		}
		res /= (nNodes*(nNodes-1));
		printf("Case %d: average length between pages = %.3f clicks\n", test, res);
	}

	return 0;
}