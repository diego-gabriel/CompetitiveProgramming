#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

#define INF 0x0fffffff

vector < vector <int> > grafo;
vector < vector <int> > dist;
vector < vector <int> > parent;

void initGraph(int n) //Inicializa matriz de adyacencias en infinito
{
	vector <int> aux;
	for (int i = 0; i < n; i++)
		aux.push_back(INF);
	for (int i = 0; i < n; i++)
		grafo.push_back(aux);
	dist = grafo;	

	aux.clear();
	for (int i = 0; i < n; i++)
		aux.push_back(-1);
	for (int i = 0; i < n; i++)
		parent.push_back(aux);

}

string toString(int n)
{
	string res = "";

	while (n)
	{
		res += (n % 10) + '0';
		n /= 10;
	}

	return res;
}

void floydWarshall()
{
	int nNodos = grafo.size();
		
	dist = grafo;

	for (int i = 0; i < nNodos; i++)
		dist[i][i] = 0;

	for (int k = 0; k < nNodos; k++)
		for (int i = 0; i < nNodos; i++)
			for (int j = 0; j < nNodos; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					parent[i][j] = k;
				}
}

string path(int origen, int destino)
{
	string res = "";

	if (dist[origen][destino] == INF)
		res = "no Path";
	else
	{
		int k = parent[origen][destino];

		if (k == -1)
			res = " ";
		else res = path(origen, k) + toString(k) + path(k, destino);
	}

	return res;
}

int main()
{
	int nNodos, nAristas, origen, destino, peso;
	
	cin>>nNodos>>nAristas;

	initGraph(nNodos);

	for (int i = 0; i < nAristas; i++)
	{
		cin>>origen>>destino>>peso;
		grafo[origen][destino] = peso;
	}

	floydWarshall();

	int nQuery;
	cin>>nQuery;

	while (nQuery--)
	{
		cin>>origen>>destino;

		cout<<"Distancia de "<<origen<<" a "<<destino<<" es: "<<dist[origen][destino]<<endl;
		cout<<"Path: "<<path(origen, destino)<<endl<<endl;
	}

	return 0;
}