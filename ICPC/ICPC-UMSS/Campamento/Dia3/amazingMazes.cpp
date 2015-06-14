#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

string makeLine(int n)
{
	string res = "";

	n *= 2;
	n;

	while (n--)
		res += "-";

	return res;
}

string makeVer(string cad)
{
	string res = "";

	for (int i = 0; i < cad.length(); i++)
	{
		if (cad[i] == '1') 
			res += "|";
		else res += " ";
	}

	return "|" + res + " |";
}

string makeHor(string cad)
{
	string res = "";

	for (int i = 0; i < cad.length(); i++)
	{
		if (cad[i] == '1')
			res += "-";
		else
			res += " ";
	}

	return "-" + res + "-";
}

struct Pos
{
	int x, y, d;

	Pos(){x = y = d = 0;}
	Pos(int a, int b)
	{
		x = a; 
		y = b;
		d = 1;
	}
};

int main()
{
	int x, y;


	while (cin>>x>>y && (x || y))
	{
		cin.ignore();
		string maze[2*y+1];
		maze[0] = maze[2*y] = makeLine(x);
		for (int i = 1; i < 2*y; i++)
		{
			getline(cin, maze[i]);
			if (i % 2)
				maze[i] = makeVer(maze[i]);
			else 
				maze[i] = makeHor(maze[i]);

		}

		queue <Pos> cola;
		cola.push(Pos(1, 1));

		maze[1][1] = 'X';
		Pos origen, destino;
		int i, j;

		bool found = false;

		while (!cola.empty())
		{
			origen = cola.front();
			cola.pop();

			found = origen.x == 2*x-1 && origen.y == 2*y-1;

			if (found) break;

			destino.d = origen.d + 1;
			i = origen.x;
			j = origen.y;
			if (maze[j][i+1] == ' ' && maze[j][i+2] == ' ')
			{
				destino.x = i + 2;
				destino.y = j;
				maze[j][i+2] = 'X';
				cola.push(destino);
			}
			if (maze[j][i-1] == ' ' && maze[j][i-2] == ' ')
			{
				destino.x = i - 2;
				destino.y = j;
				maze[j][i-2] = 'X';
				cola.push(destino);
			}
			if (maze[j+1][i] == ' ' && maze[j+2][i] == ' ')
			{
				destino.x = i;
				destino.y = j + 2;
				maze[j+2][i] = 'X';
				cola.push(destino);
			}
			if (maze[j-1][i] == ' ' && maze[j-2][i] == ' ')
			{
				destino.x = i;
				destino.y = j - 2;
				maze[j-1][i] = 'X';
				cola.push(destino);
			}
		}

		/*for (int i = 0; i < 2*y+1; i++)
			cout<<maze[i]<<endl;
*/
		if (found) cout<<origen.d<<endl;
		else cout<<0<<endl;

	}
	return 0;
}