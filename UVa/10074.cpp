#include <iostream>

using namespace std;

int main()
{
	int n, m, min;

	while (cin>>m>>n && (m || n))
	{
		min = -(n*m);

		int forest[m][n];
		int f;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				cin>>f;
				forest[i][j] = f ? min : 1;
			}

		int bestSum = 0;
		int actSum;
		int sumCol[n];

		for (int i = 0; i < m; i++)
		{

			for (int j = 0; j < n; j++)
				sumCol[j] = 0;

			for (int x = i; x < m; x++)
			{
				actSum = 0;

				for (int y = 0; y < n; y++)
				{
					sumCol[y] += forest[x][y];
					actSum += sumCol[y];

					if (actSum > bestSum)
						bestSum = actSum;
					if (sumCol[y] < 0)
						actSum = 0;
				}
			}
		}

		cout<<bestSum<<endl;
	}
	return 0;
}