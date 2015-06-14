#include <iostream>

using namespace std;

int main()
{
	int n, m, k;

	cin>>n>>m>>k;

	int row[n];
	int col[m];
	int tab[n][m];

	for (int i = 0; i < n; i++)
		row[i] = i;

	for (int i = 0; i < m; i++)
		col[i] = i;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin>>tab[i][j];
		}
	}

	int x, y;
	char q;

	for (int i = 0; i < k; i++)
	{
		cin>>q>>x>>y;
		if (q == 'c')
			swap(col[x-1], col[y-1]);
		if (q == 'r')
			swap(row[x-1], row[y-1]);
		if (q == 'g')
			cout<<tab[row[x-1]][col[y-1]]<<endl;
	}

	return 0;
}