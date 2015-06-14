#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define INF 0x0fffffff

set <pair <int, int> > aristas;
int dist[105][105];
int nNodes;

void initGraph()
{
	for (int i = 0; i <= nNodes; i++)
		for (int j = 0; j <= nNodes; j++)
			dist[i][j] = INF;

	aristas.clear();
}

void readGraph()
{
	int peso;

	initGraph();

	for (int i = 1; i < nNodes; i++)
		for (int j = 1; j <= i; j++)
		{
			cin>>peso;
			dist[i+1][j] = dist[j][i+1] = peso;
			aristas.insert(make_pair(min(i+1, j), max(i+1, j)));
		}
}

void printPair(pair <int, int> p)
{
	int x, y;
	x = p.first;
	y = p.second;

	cout<<x<<" "<<y<<" "<<dist[x][y]<<endl;
}

void print()
{
	set <pair <int, int> > :: iterator it;

	cout<<aristas.size()<<endl;
	for (it = aristas.begin(); it != aristas.end(); it++)
	{
		printPair(*it);
	}

}

bool floydWarshall()
{
	bool res = true;

	for (int i = 1; i <= nNodes; i++)
		dist[i][i] = 0;

	for (int k = 1; k <= nNodes && res; k++)
		for (int i = 1; i <= nNodes && res; i++)
			for (int j = 1; j <= nNodes && res; j++)
			{	
				if (k == i || k == j) continue;
				int toK = dist[i][k] + dist[k][j];
				res = toK >= dist[i][j];

				if (toK == dist[i][j])
				{
					aristas.erase(make_pair(min(i, j), max(i, j)));
				}

			/*	if (!res)
					{
						cout<<"error: "<<i<<" "<<j<<" in "<<k<<endl;
						cout<<"espected: "<<toK<<endl;
						cout<<"found: "<<dist[i][j]<<endl;
					}
*/
			}

	return res;
}

int main()
{
	int nTest;
	cin>>nTest;

	for (int i = 1; i <= nTest; i++)
	{
		if (i > 1) cout<<endl;
		cout<<"Case #"<<i<<":"<<endl;
		cin>>nNodes;
		readGraph();
		if (floydWarshall())
		{
			print();
		}
		else cout<<"Need better measurements."<<endl;
	}

	return 0;
}