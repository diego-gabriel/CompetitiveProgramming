#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while (t--)
	{
		int x, y;

		cin>>x>>y;

		bool esPrimo[505];

		memset(esPrimo, true, sizeof(esPrimo));
		esPrimo[0] = esPrimo[1] = false;
		
		for (int i = 2; i < 80; i++)
		{
			if (esPrimo[i])
				for (int k = 2*i; k < 505; k += i)
					esPrimo[k] = false;
		}

		int nPrime[505];

		nPrime[0] = 0;

		for (int i = 1; i < 505; i++)
			nPrime[i] = nPrime[i-1] + esPrimo[i];

		char tab[x+2][y+2];
		memset(tab, '#', sizeof(tab));

		for(int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
				cin>>tab[i][j];

		int res = 0;

		int u, d, l, r;

		int left[x+2][y+2];
		int rigth[x+2][y+2];
		int up[x+2][y+2];
		int down[x+2][y+2];


		for(int i = 1; i <= x+1; i++)
		{
			left[i][0] = 0;
			rigth[i][y+1] = 0;
			for (int j = 1; j <= y+1; j++)
			{
				if (tab[i][j-1] == '^')
					left[i][j] = left[i][j-1] + 1;
				else 
					left[i][j] = 0;

				if (tab[i][y-j+2] == '^')
					rigth[i][y-j+1] = rigth[i][y-j+2] + 1;
				else 
					rigth[i][y-j+1] = 0;
			}
		}

		for (int i = 1; i <= y+1; i++)
		{
			up[0][i] = 0;
			down[x+1][i] = 0;
			for (int j = 1; j <= x+1; j++)
			{
				if (tab[j-1][i] == '^')
					up[j][i] = up[j-1][i] + 1;
				else 
					up[j][i] = 0;

				if (tab[x-j+2][i] == '^')
					down[x-j+1][i] = down[x-j+2][i] + 1;
				else 
					down[x-j+1][i] = 0;
			}
		}


		for(int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
			{
				if (tab[i][j] == '#') continue;

				//cout<<i<<" "<<j<<endl;
				u = up[i][j];
				d = down[i][j];
				l = left[i][j];
				r = rigth[i][j];

				/*cout<<"u;"<<u<<endl;
				cout<<"d;"<<d<<endl;
				cout<<"r;"<<r<<endl;
				cout<<"l;"<<l<<endl;
/*/				//cout<<min(min(u, d), min(l, r))<<endl;
				//cout<<"ok"<<endl;
				res += nPrime[min(min(u, d), min(l, r))];
			}

		cout<<res<<endl;
	}

	return 0;
}