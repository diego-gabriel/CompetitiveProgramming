#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string tab[550];
int tam[550][550];
int ta[550][550];
int up[550][550];
int lef[550][550];

int dfs(int x, int y)
{
	if (tam[x][y] != 0)
		return tam[x][y];
	tab[x][y] = '#';
	if (tab[x][y+1] == '.')
	{
		tam[x][y+1] = dfs(x, y+1);
	}
	if (tab[x+1][y] == '.')
	{
		tam[x+1][y] = dfs(x+1, y);
	}

	tab[x][y] = '.';
	return max(tam[x+1][y], tam[x][y+1])+1;
}

void dfsta(int x, int y)
{
	tab[x][y] = '#';
	if (tab[x][y+1] == '.')
	{
		ta[x][y+1] = ta[x][y] + 1;
		dfsta(x, y+1);
	}
	if (tab[x+1][y] == '.')
	{
		ta[x+1][y] = ta[x][y] + 1;
		dfsta(x+1, y);
	}

	tab[x][y] = '.';
}

void print(int n, int m)
{
	cout<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout<<" "<<tam[i+1][j+1];
		cout<<endl;
	}
	cout<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout<<" "<<ta[i+1][j+1];
		cout<<endl;
	}
	cout<<endl<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout<<" "<<up[i+1][j+1];
		cout<<endl;
	}
	cout<<endl<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout<<" "<<lef[i+1][j+1];
		cout<<endl;
	}
}

void fill(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (tab[i][j] == '#') continue;
			up[i][j] = 1 + max(up[i-1][j], tam[i][j+1]);
		    lef[i][j] = 1 + max(lef[i][j-1], tam[i+1][j]);
		}
	}
}

int solve(int n, int m)
{
	int res = 0;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tam[i][j] == 0 && tab[i][j] == '.')
				tam[i][j] = dfs(i, j);
		}
	}
	ta[1][1] = 1;
	dfsta(1, 1);

	fill(n, m);
	//print(n, m);
	
	int tIn = tam[1][1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int goLeft = ta[i][j] + lef[i+1][j];
			int goUp =  (ta[i][j-1] != 0 ? ta[i][j-1] + up[i][j]: 0);

			res = max(max(goLeft,goUp), max(res, ta[i][j] + tam[i][j]-1));
			
		}
	}

	return res;
}

void init()
{
	string cad = "";
	for (int i = 0; i < 550; i++)
	{
		cad = cad + "#";
	}

	for (int i = 0; i < 550; i++)
		tab[i] = cad;

	memset(tam, 0, sizeof(tam));
	memset(ta, 0, sizeof(ta));
	memset(up, 0, sizeof(up));
	memset(lef, 0, sizeof(lef));
}

int main()
{
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++)
	{
		init();
		int n, m;
		cin>>n>>m;
		string cad;
		
		for (int i = 0; i < n; i++)
		{
			cin>>cad;
			tab[i+1] = "#" + cad + "#";
		}

		cout<<"Case #"<<test<<": ";
		cout<<solve(n, m)<<endl;
		

	}
	return 0;
}