#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	int nNodes;
	int n;
	int index = -1;
	while (cin>>nNodes)
	{
		index++;
		cout<<"matrix for city "<<index<<endl;
		n = -1;
		int origen, destino;
		queue <pair <int, int> > ways;

		while (nNodes--)
		{
			cin>>origen>>destino;
			ways.push(make_pair(origen, destino));
			n = max(n, max(origen, destino));
		}

		n++;

		bool path[n][n];
		memset(path, false, sizeof(path));
		int nOfPaths[n][n];
		memset(nOfPaths, 0, sizeof(nOfPaths));

		for (int i = 0; i < n; i++)
			path[i][i] =  true;//nOfPaths[i][i] = true;
		pair <int, int> way;

		while (!ways.empty())
		{
			way = ways.front();
			origen = way.first;
			destino = way.second;
			ways.pop();
			path[origen][destino] = nOfPaths[origen][destino] = true;
		}

		for (int k = 0; k < n; k++)
			for (int j = 0; j < n; j++)
				for (int i = 0; i < n; i++)
				{
					if (path[i][k] && path[k][j] && i != k && k != j)
					{
						nOfPaths[i][j] += (nOfPaths[i][k] * nOfPaths[k][j]);
						path[i][j] = true;
					}
				}


		for (int k = 0; k < n; k++)
			if (nOfPaths[k][k] > 0)
			for (int i = 0; i < n; i++)
			{
					for (int j = 0; j < n; j++)
					{
						if (path[i][k] && path[k][j])
							nOfPaths[i][j] = -1;
					}
			}

		for (int i = 0; i < n; i++)
		{
			cout<<nOfPaths[i][0];
			for (int j = 1; j < n; j++)
			{
				cout<<" "<<nOfPaths[i][j];
			}
			cout<<endl;
		}

	}
	return 0;
}