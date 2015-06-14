#include <iostream>
#include <algorithm>

using namespace std;

bool orden (int a, int b)
{
	return a < b;
}

int main()
{
	int n;
	int test = 0;
	string cad;
	int v;
	while (cin>>cad>>v>>n)
	{
		test++;
		int m[n];
		int bestRes = 0;

		for (int i = 0; i < n; i++)
			cin>>m[i];

		sort(m, m+n, orden);

		for (int i = 0; i < n; i++)
		{
			bestRes = max(bestRes, m[i]*(n - i));
		}

		cout<<"Salida para el ejemplo "<<test<<endl<<bestRes<<endl;

	}

	return 0;
}