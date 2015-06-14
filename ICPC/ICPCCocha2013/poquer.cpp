//ESTE ES EL INUNDACION!!

#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int parent[1005];

int find_parent(int a)
{
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
} 

void init()
{
	for (int i = 0; i < 1005; i++)
		parent[i] = i;
}

struct Ciudad
{
	double x, y;
	int id;

	Ciudad()
	{
		x = y = 0.0;
		id = 0;
	}

	void leer(int i)
	{
		id = i;
		cin>>x>>y;
	}
};

struct Arista
{
	Ciudad a, b;

	Arista()
	{}

	Arista(Ciudad x, Ciudad y)
	{
		a = x;
		b = y;
	}

	double dist()
	{
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}

	int max (int a, int b)
	{
		return a > b ? a : b;
	}

	bool unir(int &v)
	{
		bool res;

		int r1, r2;

		r1 = find_parent(a.id);
		r2 = find_parent(b.id);

		res = r1 != r2;

		parent[r1] = r2;


		if (res)
			v = max(v, dist());
		return res;
	}
};

bool orden(Arista a, Arista b)
{
	return a.dist() < b.dist();
}

int main()
{
	int nTest;

	cin>>nTest;

	for(int test = 1; test <= nTest; test++)
	{
		int nCiudades;
		init();
		cin>>nCiudades;

		Ciudad ciudades[nCiudades + 5];

		for (int i = 1; i <= nCiudades; i++)
		{
			ciudades[i].leer(i);
		}

		int nPuentes;

		cin>>nPuentes;

		for (int i = 1; i <= nPuentes; i++)
		{
			int x, y, r1, r2;
			cin>>x>>y;

			r1 = find_parent(x);
			r2 = find_parent(y);

			parent[r1] = r2;

		}

		vector <Arista> aristas;

		for (int i = 1; i < nCiudades; i++)
		{
			for (int j = i+1; j <= nCiudades; j++)
				aristas.push_back(Arista(ciudades[i], ciudades[j]));

		}

		sort(aristas.begin(), aristas.end(), orden);

		int in = 1;
		int res = 0;

		int i = 0;

		while (in != nCiudades && i < aristas.size())
		{
			if (aristas[i].unir(res)) in++; 
			i++;
		}

		cout<<"Caso "<<test<<": "<<res<<endl;
	}

	return 0;
}