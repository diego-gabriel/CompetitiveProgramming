#include <map>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <stack>
#include <set>

using namespace std;

struct Input
{
	string origen;
	string destino;
	string ID;
	int dist;

	Input()
	{
		origen = destino = ID = "";
		dist = 0;
	}

	Input(string line)
	{
		origen = destino = ID = "";
		dist = 0;
		int i = 0;
		line = line + ",";
		origen = readLine(line, i);
		destino = readLine(line, i);
		if (i != line.length())
		{
			ID = readLine(line, i);
			dist = toInt(readLine(line, i));
		}
	}

	int toInt(string cad)
	{
		int res = 0;

		for (int i = 0; i < cad.length(); i++)
		{
			res *= 10;
			res += (cad[i] - '0');
		}

		return res;

	}

	string readLine(string &line, int &i)
	{
		string tar = "";
		while (line[i] != ',')
		{
			tar = tar + line[i];
			i++;
		}
		i++;
		return tar;
	}

	void swap()
	{
		string aux = destino;
		destino = origen;
		origen = aux;
	}
};

struct Vecino
{
	string city;
	string routeID;
	int dist;

	Vecino() 
	{
		city = routeID = "";
		dist = 0;
	}

	Vecino (Input in)
	{
		city = in.destino;
		routeID = in.ID;
		dist = in.dist;
	}

	int print(string endCity)
	{
		cout<<fillTo(city, 21)<<fillTo(endCity, 21)<<fillTo(routeID, 11);
		printf("%5d\n", dist);
		return dist;
	}

	string fillTo(string cad, int size)
	{
		while (cad.length() < size)
			cad = cad + " ";
		return cad;
	}

};

void printFor(stack <Vecino> ruta, string destino)
{
	printf("\n\n");
	printf("From                 To                   Route      Miles\n");
	printf("-------------------- -------------------- ---------- -----\n");

	string dest;
	ruta.pop();
	Vecino city = ruta.top();
	ruta.pop();
	int suma = 0;

	while (!ruta.empty())
	{
		suma += city.print(ruta.top().city);
		city = ruta.top();
		ruta.pop();
	}
	suma += city.print(destino);

	printf("                                                     -----\n");
	printf("                                          Total      %5d\n", suma);

}

int main()
{
	string line;
	map <string, vector <Vecino> > grafo;
	map <string, map <string, int> > dist;
	map <string, bool> calcFor;
	map <string, map <string, Vecino> > parentFrom;
	set <string> allCities;
	set <string> :: iterator it, that;

	while (getline(cin, line) && line != "")
	{
		Input input = Input(line);
		grafo[input.origen].push_back(Vecino(input));
		input.swap();
		grafo[input.origen].push_back(Vecino(input));

		allCities.insert(input.origen);
		allCities.insert(input.destino);
	}

	for (it = allCities.begin(); it != allCities.end(); it++)
	{
		for (that = allCities.begin(); that != allCities.end(); that++)
			dist[*it][*that] = 0x3fffffff;
	}

	while (getline(cin, line))
	{
		Input input = Input(line);
		string origen = input.origen;
		string destino = input.destino;
		string o, d;
		int actD, newD;

		queue <string> cola;
		dist[origen][origen] = 0;
		cola.push(origen);

		if (!calcFor[origen])
		{
			calcFor[origen] = true;
			//Dijkstra

			while (!cola.empty())
			{
				o = cola.front();
				cola.pop();
				Vecino vec;

				for (int i = 0; i < grafo[o].size(); i++)
				{
					vec = grafo[o][i];
					d = vec.city;
					if (dist[origen][d] > dist[origen][o] + vec.dist)
					{
						dist[origen][d] = dist[origen][o] + vec.dist;
						cola.push(d);
						vec.city = o;
						parentFrom[origen][d] = vec;
					}
				}
			}
		}

		stack <Vecino> ruta;
		d = destino;
		
		while (parentFrom[origen][d].city != d)
		{
			ruta.push(parentFrom[origen][d]);
			d = parentFrom[origen][d].city;
		}


		printFor(ruta, destino);




	}
	return 0;
}