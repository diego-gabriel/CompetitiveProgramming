#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Elefante
{
	int peso;
	int IQ;
	int ID;
	Elefante(int a, int b, int i)
	{
		peso = a;
		IQ = b;
		ID = i + 1;
	}

	Elefante()
	{}

	void leer(int i)
	{
		cin>>peso>>IQ;
		ID = i;
	}
};

bool orden(Elefante a, Elefante b)
{
	bool res;
	if (a.peso == b.peso)
		if (a.IQ == b.IQ)
			res = a.ID < b.ID;
		else
			res = a.IQ > b.IQ;
	else
		res = a.peso < b.peso;
	return res;
}

bool operator < (const Elefante &a, const Elefante &b)
{
	return a.peso < b.peso && a.IQ > b.IQ;
}

int main()
{
	vector <Elefante> elef;
	int peso, IQ, n, e;
	int parent[1500], lis[1500];
	int res = 0;
	n = 0;

	while(cin>>peso>>IQ)
	{
		parent[n] = n;
		lis[n] = 1;
		elef.push_back(Elefante(peso, IQ, n++));
	}

	sort(elef.begin(), elef.end(), orden);

	for (int i = n-1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (elef[i] < elef[j])
			{
				if (lis[i] < lis[j] + 1)
				{
					lis[i] = lis[j] + 1;
					parent[i] = j;
				}
			}
		}

		if (res < lis[i])
		{
			res = lis[i];
			e = i;
		}
	}


	cout<<res<<endl;
	cout<<elef[e].ID<<endl;

	while (parent[e] != e)
	{
		e = parent[e];
		cout<<elef[e].ID<<endl;
	}


	return 0;
}