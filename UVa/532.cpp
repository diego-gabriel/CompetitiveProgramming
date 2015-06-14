#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

bool tab[32][32][32];
int dist[32][32][32];
int startX, startY, startZ, endX, endY, endZ;

void leerInput(int x, int y, int z)
{
	char car;
	for (int k = 1; k <= z; k++)
	{
		for (int j = 1; j <= y; j++)
		{
			for (int i = 1; i <= x; i++)
			{
				cin>>car;

				tab[k][j][i] = car != '#';

				if (car == 'S')
				{
					startX = i;
					startY = j;
					startZ = k;
				}
				if (car == 'E')
				{
					endX = i;
					endY = j;
					endZ = k;
				}
			}
		}
	}
}

struct Pos
{
	int x;
	int y;
	int z;

	Pos(){}
	Pos(int a, int b, int c)
	{
		x = a;
		y = b;
		z = c;
	}

	vector <Pos> getVecinos()
	{
		vector <Pos> res;

		res.push_back(Pos(x+1, y, z));
		res.push_back(Pos(x, y+1, z));
		res.push_back(Pos(x, y, z+1));
		res.push_back(Pos(x, y, z-1));
		res.push_back(Pos(x, y-1, z));
		res.push_back(Pos(x-1, y, z));

		return res;
	}
};

bool operator == (const Pos &a, const Pos &b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

void visitar(const Pos &a)
{
	tab[a.z][a.y][a.x] = false;
}

int main()
{
	int x, y, z;

	while (cin>>z>>y>>x && (x || y || z))
	{
		memset(dist, -1, sizeof(dist));
		memset(tab, false, sizeof(tab));		
		leerInput(x, y, z);

		Pos start, end, origen, destino;

		start = Pos(startX, startY, startZ);
		end = Pos(endX, endY, endZ);

		queue <Pos> cola;

		cola.push(start);
		visitar(start);
		dist[start.z][start.y][start.x] = 0;

		while(!cola.empty())
		{
			origen = cola.front();
			cola.pop();

			vector <Pos> vecinos = origen.getVecinos();

			for (int i = 0; i < vecinos.size(); i++)
			{
				destino = vecinos[i];

				if (tab[destino.z][destino.y][destino.x])
				{
					cola.push(destino);

					dist[destino.z][destino.y][destino.x] = dist[origen.z][origen.y][origen.x] + 1;
					visitar(destino);
				}
			}
		}

		int res = dist[end.z][end.y][end.x];

		if (res == -1)
			cout<<"Trapped!"<<endl;
		else
			cout<<"Escaped in "<<res<<" minute(s)."<<endl;

	}




	return 0;
}