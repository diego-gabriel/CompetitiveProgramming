#include <iostream>

using namespace std;

int main()
{
	int n;
	int nTest;
	cin>>nTest;

	while (nTest--)
	{
		cin>>n;

		int torus[2*n][2*n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin>>torus[i][j];
				torus[i+n][j] = torus[i][j+n] = torus[i+n][j+n] = torus[i][j];
			}

		int bestSum = 0x80000000;
		int actSum;
		int sumCol[2*n];
		int actIniY;
		int actIniX;


		for (int i = 0; i < n; i++)
		{
			for (int y = 0; y < 2*n; y++)
				sumCol[y] = 0;

			for (int x = i; x < n+i; x++)
			{
				actIniY = 0;
				actSum = 0;

				for (int y = 0; y < 2*n; y++)
				{
					sumCol[y] += torus[x][y];
				}

				for (int y = 0; y < 2*n; y++)
				{
					actSum += sumCol[y];

					if (y - actIniY == n)
					{
						y = actIniY;
						actSum = 0;
						actIniY++;
						continue;
					}

					if (actSum > bestSum)
					{
						bestSum = actSum;
					}

					if (actSum <= 0)
					{
						actSum = 0;
						actIniY = y+1;
					}
				}
			}
		}

		cout<<bestSum;
		if (n) cout<<endl;
	}
	return 0;
}
