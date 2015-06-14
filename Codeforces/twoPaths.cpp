#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <set>

using namespace std;

map <int, vector <int> > grafo;
map <int, int> dist;
map <int, int> vis;

set <int> rem;

struct Arista
{
	int a, b;

	Arista(){};
	Arista(int c, int d)
	{
		if (c < d) swap(c, d);
		a = c;
		b = d;
	}
};

bool operator == (const Arista &a, const Arista &b)
{
	return (a.a == b.a && a.b == b.b);
}

Arista forbidden;

int bfs(int origen)
{
	int res = 0;

	vis.clear();
	queue <int> cola;
	vector <int> vecinos;

	cola.push(origen);
	vis[origen] = true;
	dist[origen] = 0;

	while (!cola.empty())
	{
		res = origen = cola.front();
		cola.pop();
		rem.erase(origen);

		vecinos = grafo[origen];
		
		for (int i = 0; i < vecinos.size(); i++)
		{
			Arista arista = Arista(origen, vecinos[i]);

			if (!vis[vecinos[i]] && !(arista == forbidden))
			{
				dist[vecinos[i]] = dist[origen] + 1;
				vis[vecinos[i]] = true;
				cola.push(vecinos[i]);
			}
		}
	}

	return res;
}

int maxLength(int node)
{
	int farNode;

	farNode = bfs(bfs(node));

	return dist[farNode];
}

int main()
{
	int nNodes, origen, destino;
	cin>>nNodes;
	set <int> currentRem;
	vector <Arista> aristas;
	currentRem.insert(nNodes);

	for (int i = 1; i < nNodes; i++)
	{
		cin>>origen>>destino;

		grafo[origen].push_back(destino);
		grafo[destino].push_back(origen);
		currentRem.insert(i);
		aristas.push_back(Arista(origen, destino));
	}

	int res = 0;

	for (int i = 0; i < nNodes - 1; i++)
	{
		rem = currentRem;
		int path1, path2;
		rem.erase(i);

		forbidden = aristas[i];

		path1 = maxLength(*rem.begin());

		if (rem.empty()) path2 = 0;
		else
			path2 = maxLength(*rem.begin());

		res = max(res, path2*path1);
	}

	cout<<res<<endl;

	return 0;
}