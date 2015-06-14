#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin>>t;

	bool esPrimo[55];

	memset(esPrimo, true, sizeof(esPrimo));
	esPrimo[0] = esPrimo[1] = false;
	for (int i = 2; i < 20; i++)
	{
		if (esPrimo[i])
			for (int k = 2*i; k < 55; k += i)
				esPrimo[k] = false;
	}

	while (t--)
	{
		int x, y;

		cin>>x>>y;


		char tab[x+2][y+2];
		memset(tab, '#', sizeof(tab));

		for(int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
				cin>>tab[i][j];

		int res = 0;

		for(int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
			{
				if (tab[i][j] == '#') continue;
				int u, d, l, r;
				u = d = l = r = 0;

				int p = i-1;

				while (tab[p][j] == '^')
				{
					p--;
					u++;
				}

				p = i+1;

				while (tab[p][j] == '^')
				{
					p++;
					d++;
				}


				p = j+1;

				while (tab[i][p] == '^')
				{
					p++;
					r++;
				}

				p = j-1;

				while (tab[i][p] == '^')
				{
					p--;
					l++;
				}

				if (min(min(u, d), min(l, r)) >= 2)
					res++;
			}

		cout<<res<<endl;
	}

	return 0;
}