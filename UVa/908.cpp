#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int parent[1000000 + 1];

int find_parent(int a){
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
}

struct Line{
	int origen, destino, peso;
	Line(){};

	void read(){
		scanf("%d %d %d", &origen, &destino, &peso);
	}

	bool disjoint(){
		int pOrigen = find_parent(origen);
		int pDestino = find_parent(destino);

		return pOrigen != pDestino;
	}

	void join(){
		int pOrigen = find_parent(origen);
		int pDestino = find_parent(destino);

		parent[pOrigen] = pDestino;		
	}
};

void init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i+1] = i+1;
}

bool orden (Line a, Line b){
	return a.peso < b.peso;
}

int main()
{
	int n;
	bool first = true;
	while (cin>>n){
		if (!first) cout<<endl;
		Line lines[n + 10];
		init(n);
		int sumBefore = 0;
		for (int i = 0; i < n-1; i++)
		{
			lines[i].read();
			sumBefore += lines[i].peso;
		}

		int k;

		cin>>k;

		for (int i = 0; i < k; i++)
			lines[i+n-1].read();

		sort(lines, lines + (n+k-1), orden);

		int l;
		Line aux;
		cin>>l;
		for (int i = 0; i < l; i++) aux.read();
		int i = 0;
		int res = 0;
		n--;	
		Line linea;

		while (n){
			linea = lines[i];
			if (linea.disjoint())
			{
				linea.join();
				res += linea.peso;
				n--;
			}
			i++;
		}

		cout<<sumBefore<<endl<<res<<endl;
		first = false;

	}
	return 0;
}