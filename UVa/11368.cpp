#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct Doll
{
	int w, h;
	Doll()
	{
		w = h = 0;
	}

	void leer()
	{
		cin>>w>>h;
	}
};

bool operator < (const Doll &a, const Doll &b)
{
	return a.w < b.w && a.h < b.h;
}

bool operator > (const Doll &a, const Doll &b)
{
	return a.w > b.w && a.h > b.h;
}

Doll doll[20001];
int lis[20001];
int parent[20001];

int findIndex(Doll &d, int ini, int fin)
{
	int res;
	if (fin == 0) res = 0;
	else
		if (ini == fin && !(d < doll[ini]))
			res = 0;
		else
		{
			int mid = (ini + fin) / 2;
			if (doll[mid] < d)
				res = findIndex(d, mid + 1, fin);
			else
			{
				if (mid == 0) res = 0;
				else
				{
					if (doll[mid - 1] < d)
						res = mid;
					else
					{
						res = findIndex(d, ini, mid);
					}
				}
			}
		}
	return res;
}

int find(int a)
{
	return parent[a] == a ? a : parent[a] = find(parent[a]);
}

bool orden (Doll a, Doll b)
{
	if (a.w == b.w)
		return a.h < b.h;
	return a.w < b.w;
}

int main()
{
	int nTest;

	cin>>nTest;

	while (nTest--)
	{
		int n;
		cin>>n;


		for (int i = 0; i < n; i++)
		{
			doll[i].leer();
			parent[i] = i;
		}

		sort(doll, doll + n, orden);
		int last = -1;

		map <int, int> belong;
		int res = 1;

		for (int i = 0; i < n; i++)
		{
			if (last == -1)
			{
				last++;
				lis[last] = i;
				belong[i] = res;
			}
			else
			{
				if (doll[lis[last]] < doll[i])
				{
					last++;
					lis[last] = i;
					belong[i] = res;
				}
				else
				{ 
					int index = findIndex(doll[i], 0, last);
					lis[index] = i;
					if (index == 0)
					{
						res++;
					}
					else
					{
						if (belong[index] == belong[index-1])
						{
							res++;
						}
					}

					belong[i] = res;
				}
			}
		}
		cout<<res<<endl;


	}


	return 0;
}