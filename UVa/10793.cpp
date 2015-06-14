#include <iostream>

using namespace std;

#define INF 0x0fffffff

int dist[105][105];
int nNodos;

void initGraph()
{
	for(int i = 0; i < nNodos; i++)
		for (int j = 0; j < nNodos; j++)
			dist[i][j] = INF;
}

void readGraph(int n)
{
	initGraph();

	int origen, destino, peso;

	for (int i = 0; i < n; i++)
	{
		cin>>origen>>destino>>peso;
		origen--;
		destino--;
		dist[origen][destino] = min(peso, dist[origen][destino]);
		dist[destino][origen] = min(peso, dist[destino][origen]);
	}
}

void floydWarshall()
{
	for (int i = 0; i < nNodos; i++)
		dist[i][i] = 0;

	for (int k = 0; k < nNodos; k++)
		for (int i = 0; i < nNodos; i++)
			for (int j = 0; j < nNodos; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
}

int maxFila(int k)
{
	int res = dist[k][0];
	bool ok = true;

	for (int i = 1; i < 5 && ok; i++)
	{
		ok = dist[k][i] == res;
	}

	for (int i = 5; i < nNodos && ok; i++)
		res = max(res, dist[k][i]);
	
	return ok ? res : INF;
}

int main()
{
	int nTest;
	cin>>nTest;

	for (int i = 0; i < nTest; i++)
	{
		int nAristas;
		cin>>nNodos>>nAristas;

		readGraph(nAristas);
		floydWarshall();

		int res = INF;
		if (nNodos >= 5)
		{
			for (int i = 0; i < nNodos; i++)
			{
				res = min(res, maxFila(i));
			}
		}

		if (res == INF)
			res = -1;

		cout<<"Map "<<i+1<<": "<<res<<endl;

	}
	return 0;
}