#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

string tab[10];
int origenX, origenY, destinoX, destinoY;

void initTab()
{
	tab[0] = "**********";
	tab[1] = "*        *";
	tab[2] = "*        *";
	tab[3] = "*        *";
	tab[4] = "*        *";
	tab[5] = "*        *";
	tab[6] = "*        *";
	tab[7] = "*        *";
	tab[8] = "*        *";
	tab[9] = "**********";
}

queue <string> dfs(int x, int y)
{
	stack <string> res;

	map <pair <int, int>, queue <string> > path;
	queue <pair<int, int> > cola;
	queue <string> oPath;
	cola.push(make_pair(x, y));
	tab[x][y] = '*';
	pair <int, int> origen, destino;

	while (!cola.empty())
	{
		origen = cola.front();
		cola.pop();

		x = origen.first;
		y = origen.second;

		if (tab[x+1][y] == ' ')
		{	
			destino = make_pair(x+1, y);
			path[destino] = path[origen];
			path[destino].push("R");
			tab[x+1][y] = '*';	
			cola.push(destino);
		}
		if (tab[x][y+1] == ' ')
		{	
			destino = make_pair(x, y+1);
			path[destino] = path[origen];
			path[destino].push("U");
			tab[x][y+1] = '*';	
			cola.push(destino);
		}
		if (tab[x-1][y] == ' ')
		{	
			destino = make_pair(x-1, y);
			path[destino] = path[origen];
			path[destino].push("L");
			tab[x-1][y] = '*';	
			cola.push(destino);
		}
		if (tab[x][y-1] == ' ')
		{	
			destino = make_pair(x, y-1);
			path[destino] = path[origen];
			path[destino].push("D");
			tab[x][y-1] = '*';	
			cola.push(destino);
		}
		if (tab[x+1][y+1] == ' ')
		{	
			destino = make_pair(x+1, y+1);
			path[destino] = path[origen];
			path[destino].push("RU");
			tab[x+1][y+1] = '*';	
			cola.push(destino);
		}
		if (tab[x-1][y-1] == ' ')
		{	
			destino = make_pair(x-1, y-1);
			path[destino] = path[origen];
			path[destino].push("LD");
			tab[x-1][y-1] = '*';	
			cola.push(destino);
		}
		if (tab[x+1][y-1] == ' ')
		{	
			destino = make_pair(x+1, y-1);
			path[destino] = path[origen];
			path[destino].push("RD");
			tab[x+1][y-1] = '*';	
			cola.push(destino);
		}
		if (tab[x-1][y+1] == ' ')
		{	
			destino = make_pair(x-1, y+1);
			path[destino] = path[origen];
			path[destino].push("LU");
			tab[x-1][y+1] = '*';	
			cola.push(destino);
		}
	}


	return path[make_pair(destinoX, destinoY)];
}

int main()
{
	initTab();

	string origen, destino;
	
	cin>>origen>>destino;	

	origenX = origen[0] - 'a' + 1;
	destinoX = destino[0] - 'a' + 1;
	origenY = origen[1] - '0';
	destinoY = destino[1] - '0';
	
	queue <string> res = dfs(origenX, origenY);

	cout<<res.size()<<endl;

	while (!res.empty())
	{
		cout<<res.front()<<endl;
		res.pop();
	}
	return 0;
}