#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

#define Grafo map <int, vector <int> >
bool marked[100001];
int dist[100001];

bool ord(int a, int b)
{
	return a < b;
}

int farDfs(int o, int d)
{
	
}

int main()
{
	Grafo grafo;

	int n, m, d;
	memset(marked, false, sizeof(marked));
	memset(vis, , sizeof(vis));
	cin>>n>>m>>d;

	int s;
	for (int i = 0; i < m; i++)
	{	
		cin>>s;
		marked[s] = true;
	}

	int origen, destino;

	for (int i = 1; i < n; i++)
	{
		cin>>origen>>destino;

		grafo[origen].push_back(destino);
		grafo[destino].push_back(origen);
	}

	int far = farDfs(1, d);

	return 0;
}