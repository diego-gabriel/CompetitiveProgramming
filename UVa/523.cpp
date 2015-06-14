#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define INF 0x7fffffff

int count(string cad)
{
	int res = 1;
	bool inSpace = false;
	for (int i = 0; i < cad.length(); i++)
	{
		if (cad[i] == ' ' && !inSpace)
			res++;
		inSpace = cad[i] == ' ';
	}
	cout<<res<<endl;
	return res;
}

vector <string> split(string cad)
{
	bool inSpace = false;

	vector <string> tokens;
	string token = "";

	for (int i = 0; i < cad.length(); i++)
	{
		if (cad[i] == ' ' && !inSpace)
		{
			tokens.push_back(token);
			token = "";
		}

		inSpace = cad[i] == ' ';

		if (!inSpace)
		{
			token = token + cad[i];
		}
	}

	tokens.push_back(token);

	return tokens;
}

int parseToInt (string cad)
{
	int res = 0;
	int signo = 1;
	int i = 0;

	if (cad[0] == '-')
	{
		signo = -1;
		i = 1;
	}

	while (i < cad.length())
	{
		res *= 10;
		res += (cad[i] - '0');
		i++;
	}

	return signo * res;
}

vector <int> splitNparse(string cad)
{
	vector <int> res;
	vector <string> tok = split(cad);

	res.push_back(0);

	for (int i = 0; i < tok.size(); i++)
	{
		res.push_back(parseToInt(tok[i]));
	}

	return res;
}

vector <pair <int, int> > parse(string cad)
{
	vector <pair <int, int> > res;
	
	vector <string> tokens = split(cad);
	for (int i = 0; i < tokens.size(); i++)
	{
		int val = parseToInt(tokens[i]);
		if (val != -1)
			res.push_back(make_pair(i+1, val));
	}
	return res;
}

int floyd (map <int, vector <pair <int, int> > > &grafo, vector <int> &tax, int origen, int destino)
{
	int res;
	int dist[tax.size() + 1][];
	int origenIn = origen;
	int destinoIn = destino;
	map <int, int> parent;

	for (int i = 0; i < tax.size()+1; i++)
	{
		dist[i] = INF;
	}



	return res;
}

int main()
{
	int nTest;
	cin>>nTest;
	cin.ignore();
	string cad;
	getline(cin, cad);

	for(int i = 0; i < nTest; i++)
	{
		getline(cin, cad);
		int n = count(cad);

		vector < vector <pair <int, int> > > grafo;
		vector <int> tax;


		for (int k = 1; k <= n; k++)
		{
			grafo[k] = parse(cad);
			getline(cin, cad);
		}

		tax = splitNparse(cad);
		getline(cin, cad);

		do
		{
			vector <string> par = split(cad);
			int origen, destino;
			origen = cad[0];
			destino = cad[1];

			cout<<floyd(grafo, tax, origen, destino)<<endl;
		
		} while (getline(cin, cad) && cad != "");
		
	}


	return 0;
}