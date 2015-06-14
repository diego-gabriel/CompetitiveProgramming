#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

string formula[1000][18279];
int valor[1000][18279];
bool evaluado[1000][18279];

int parse(string cad)
{
	int res = 0;

	for(int i = 0; i < cad.length(); i++)
	{
		res *= 10;
		res += (cad[i] - '0');
	}

	return res;
}

vector <string> split(string cad)
{
	vector <string> res;
	string aux = "";

	for (int i = 0; i < cad.length(); i++)
	{
		if (cad[i] == '+')
		{
			res.push_back(aux);
			aux = "";
		}
		else
			aux += cad[i];
	}

	res.push_back(aux);

	return res;
}

pair <int, int> parsePair(string cad)
{
	pair <int, int> res;
	int num = 0;
	bool fst = false;
	for (int i = 0; i < cad.length(); i++)
	{
		if (!fst && isdigit(cad[i]))
		{
			res.first = num - 1;
			num = 0;
			fst = true;
		}

		if (fst)
		{
			num *= 10;
			num += (cad[i] - '0');
		}

		if (!fst)
		{
			num *= 26;
			num += (1 + cad[i] - 'A');
		}
	}

	res.second = num - 1;

	return res;
}

int parse(int x, int y)
{
	int res = 0;

	if (formula[x][y][0] == '=')
	{
		vector <string> tokens = split(formula[x][y].substr(1));

		for (int i = 0; i < tokens.size(); i++)
		{
			pair<int, int> pos = parsePair(tokens[i]);

			int x, y;
			y = pos.first;
			x = pos.second;

			if (evaluado[x][y])
				res += valor[x][y];
			else
				res += valor[x][y] = parse(x, y);
		}
	}
	else
	{
		res = parse(formula[x][y]);
	}

	evaluado[x][y] = true;
 
	return res;
}


int main()
{
	int nTest;

	cin>>nTest;

	while (nTest--)
	{
		int x, y;
		cin>>x>>y;

		for (int j = 0; j < y; j++)
		{
			for (int i = 0; i < x; i++)
			{
				cin>>formula[j][i];	
				evaluado[j][i] = false;
			}
		}

		for (int j = 0; j < y; j++)
			for (int i = 0; i < x; i++)
				if (!evaluado[j][i])
					valor[j][i] = parse(j, i);

		for (int j = 0; j < y; j++)
		{
			cout<<valor[j][0];

			for (int i = 1; i < x; i++)
				cout<<" "<<valor[j][i];
			cout<<endl;
		}
	}

	return 0;
}