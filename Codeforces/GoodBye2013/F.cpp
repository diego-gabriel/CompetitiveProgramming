#include <iostream>
#include <vector>
#include <map>

struct Nodo
{	
	int parent;
	int dist;
	Nodo()
	{
		parent = 0;
		dist = 0;
	}
}nodo[3000000];

int main()
{
	int n;
	cin>>n;
	int hoja;

	int diam = 2;
	int last = 4;

	nodo[1].parent = 1;
	nodo[1].dist = 1;

	nodo[2].parent = 1;
	nodo[3].parent = 1;
	nodo[4].parent = 1;

	nodo[2].dist = 0;
	nodo[3].dist = 0;
	nodo[4].dist = 0;


	for (int i = 0; i < n; i++)
	{
		int hoja;
		nodo[last + 1].parent = hoja;
		nodo[last + 2].parent = hoja;

		last += 2;

		update(hoja);

		cout<<nodo[1].distL + 
	}

	return 0;
}