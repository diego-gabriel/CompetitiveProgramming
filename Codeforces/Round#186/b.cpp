#include <cstring>
#include <iostream>

using namespace std;

string cad;

int arbol[100000 * 4];

void init(int ini, int fin, int nodo)
{
	if (ini == fin) arbol[nodo] = cad[ini] == cad[ini + 1];
	else
	{
		int mid = (ini + fin) / 2;
		
		init (ini, mid, nodo*2 + 1);
		init (mid + 1, fin, nodo*2 + 2);
		
		
		arbol[nodo] = arbol[nodo*2 + 1] + arbol [nodo*2 + 2];
	} 
}

int query (int ini, int fin, int nodo, int l, int r)
{
	int res;
	
	if (ini == l && r == fin) res = arbol[nodo];
	else
	{
		int mid = (ini + fin) / 2;
		if (r <= mid) res = query(ini, mid, nodo*2 + 1, l, r);
		else if (l > mid) res = query(mid + 1, fin, nodo*2 + 2, l, r);
		else
		{
			int left = query(ini, mid, nodo*2 + 1, l, mid);
			int rigth = query(mid + 1, fin, nodo*2 + 2, mid + 1, r);
			
			res = left + rigth;
		}
	}
	
	return res;
}

int main()
{
	int n, l, r;
	cin>>cad;
	cin>>n;
	int len = cad.length()-2;
	init(0, len, 0);
	
	
	for (int i = 0; i < n; i++)
	{
		cin>>l>>r;
		cout<<query(0, len, 0, l-1, r-2)<<endl;
	}
	
	
	return 0;
}
