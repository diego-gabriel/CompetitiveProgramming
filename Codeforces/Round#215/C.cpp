#include <iostream>
#include <cstring>

using namespace std;

int abs(int a)
{
	return a > 0 ? a : -a;
}

struct Solver
{
	int x, y, z;

	Solver(){
		x = y = z = 0;
	}

	void add(char k)
	{
		if (k == 'x') x++;
		if (k == 'y') y++;
		if (k == 'z') z++;
	}

	bool solve()
	{
		bool res;
		int nCop = min(min(x, y), z);

		res = max(abs(x - nCop), max(abs(y - nCop), abs(z - nCop))) <= 1 || (x + z + y) < 3;

		return res;
	}

};

Solver operator - (Solver a, Solver b)
{
	Solver res;
	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return res;
}

int main()
{
	string cad;
	cin>>cad;
	Solver solver[cad.length() + 1];

	for (int i = 0; i < cad.length(); i++)
	{
		solver[i+1] = solver[i];
		solver[i+1].add(cad[i]);
	}

	int n;

	cin>>n;

	int l, r;

	for (int i = 0; i < n; i++)
	{
		cin>>l>>r;

		Solver res = solver[r] - solver[l-1];

		if (res.solve()) cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}