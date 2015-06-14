#include <cstring>
#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct Pos
{
	int x;
	int y;
	char orientation;

	Pos(){}

	vector <Pos> getNextDirections(int limY, int limX)
	{
		vector <Pos> res;

		Pos pos;
		pos.x = x;
		pos.y = y;

		switch (orientation)
		{
			case 'n': {
				pos.orientation = 'w';
				res.push_back(pos);
				pos.orientation = 'e';
				res.push_back(pos);
				pos.orientation = 'n';	
				pos.y = y-1;
				res.push_back(pos);
				pos.y = y-2;
				res.push_back(pos);
				pos.y = y-3;
				res.push_back(pos);
			} break;
			case 's': {
				pos.orientation = 'w';
				res.push_back(pos);
				pos.orientation = 'e';
				res.push_back(pos);
				pos.orientation = 's';
				pos.y = y+1;
				res.push_back(pos);
				pos.y = y+2;
				res.push_back(pos);
				pos.y = y+3;
				res.push_back(pos);
			} break;
			case 'e':{
				pos.orientation = 's';
				res.push_back(pos);
				pos.orientation = 'n';
				res.push_back(pos);
				pos.orientation = 'e';
				pos.x = x-1;
				res.push_back(pos);
				pos.x = x-2;
				res.push_back(pos);
				pos.x = x-3;
				res.push_back(pos);
			} break;
			case 'w': {
				pos.orientation = 's';
				res.push_back(pos);
				pos.orientation = 'n';
				res.push_back(pos);
				pos.orientation = 'w';
				pos.x = x+1;
				res.push_back(pos);
				pos.x = x+2;
				res.push_back(pos);
				pos.x = x+3;
				res.push_back(pos);
			} break;

		}

		for (int i = 0; i < res.size(); i++)
		{
			if ((res[i].x < 0 || res[i].y < 0) || (res[i]. x >= limX || res[i].y >= limY))
			{
				res.erase(res.begin() + i);
				i--;
			}	
		}

		return res;
	}

};

bool operator < (const Pos &a, const Pos &b)
{
	if (a.x == b.x)
	{
		if (a.y == b.x)
			return a.orientation < b.orientation;
		else
		return a.y < b.y;
	}
	return a.x < b.x;
}

bool operator == (const Pos &a, const Pos &b)
{
	return a.x == b.x && a.y == b.y && a.orientation == b.orientation;
}

bool operator > (const Pos &a, const Pos &b)
{
	return ! (a < b) && ! (a == b);
}

bool operator <= (const Pos &a, const Pos &b)
{
	return a < b || a == b;
}

bool operator >= (const Pos &a, const Pos &b)
{
	return a > b || a == b;
}

bool operator != (const Pos &a, const Pos &b)
{
	return ! (a == b);
}

string leer()
{
	string cad, res;

	getline(cin, cad);
	res = "";

	for (int i = 0; i < cad.length(); i++)
		if (cad[i] == '0' || cad[i] == '1') res += cad[i];

	return res;
}

int main()
{
	int n, m;

	while (cin>>n>>m && (n || m))
	{
		string tab[n];

		cin.ignore();

		for (int i = 0; i < n; i++)
			tab[i] = leer();

		bool grid[n-1][m-1];

		for (int j = 0; j < n -1; j++)
			for (int i = 0; i < m - 1; i++)
			{
				grid[j][i] = !(tab[j][i] == '0' && 
							 tab[j+1][i] == '0' && 
							 tab[j][i+1] == '0' && 
							 tab[j+1][i+1] == '0');
			}

		string orientation;
		Pos origen, destino, des;
		map <char, int> visitado[n-1][m-1];

		cin>>origen.y>>origen.x>>destino.y>>destino.x>>orientation;

		origen.orientation = orientation[0];
		destino.x -= 1;
		destino.y -= 1;
		origen.x -= 1;
		origen.y -= 1;

		queue <Pos> cola;
		cola.push(origen);
		
		visitado[origen.y][origen.x][origen.orientation] = 1;

		
		while (!cola.empty())
		{
			origen = cola.front();
			cola.pop();

			char k;
			cin>>k;

			vector <Pos> vecinos = origen.getNextDirections(n-1, m-1);

			int x, y;
			char o;

			for (int i = 0; i < vecinos.size(); i++)
			{
				x = vecinos[i].x;
				y = vecinos[i].y;
				o = vecinos[i].orientation;
				des = vecinos[i];

				if (!grid[y][x] && visitado[y][x][o] == 0)
				{
					cout<<"Entra: "<<endl;

				cout<<x<<" "<<y<<" "<<o<<endl;					
					visitado[y][x][o] = visitado[origen.y][origen.x][origen.orientation] + 1;
					cola.push(des);
				}
			}
		}

		int xDes, yDes;
		xDes = destino.x;
		yDes = destino.y;

		cout<<visitado[yDes][xDes]['n']<<endl;
		cout<<visitado[yDes][xDes]['s']<<endl;
		cout<<visitado[yDes][xDes]['e']<<endl;
		cout<<visitado[yDes][xDes]['w']<<endl;

		int res = min(min(visitado[yDes][xDes]['n'], visitado[yDes][xDes]['s']) , 
				  min(visitado[yDes][xDes]['w'], visitado[yDes][xDes]['e'])) - 1;

		cout<<res<<endl;

	}

	return 0;
}