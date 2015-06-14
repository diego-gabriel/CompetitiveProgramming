#include <iostream>
#include <cstring>

using namespace std;

string tab[30];
int n;

int iHasSq(string &cad)
{
	int res = -1;
	bool ihasRes = false;
	for (int i = 0; i < n && !ihasRes; i++)
	{
		ihasRes = cad[i] == '#';
		if (ihasRes) res = i;
	}

	return res;
}

int findL(string &cad, int i)
{
	int res = 0;
	while (i < n && cad[i] == '#')
	{
		cad[i] = '.';
		res++;
		i++;
	}

	return res;
}

bool isSq(int x, int y, int len, int rem)
{
	bool res = rem == 0;

	if (!res && x < n)
	{
		if (len == findL(tab[x], y))
			res = isSq(x+1, y, len, rem-1);
	}
	return res;
}

bool hasFail(string &cad)
{
	int res = false;

	for (int i = 0;i < n && !res; i++)
	{
		res = cad[i] == '#';
	}

	return res;
}

int main()
{
	int nTest;
	cin>>nTest;

	for (int test = 0; test < nTest; test++)
	{
		cin>>n;
		for (int i = 0; i < n; i++)
			cin>>tab[i];

		bool res = false;
		bool fail = false;

		for (int i = 0; i < n && !res && !fail; i++)
		{
			int iniSq = iHasSq(tab[i]);
			//cout<<"blu"<<endl;

			if (iniSq != -1)
			{
		//		cout<<"found x = "<<i<<", y = "<<iniSq<<endl;
				int len = findL(tab[i], iniSq);
		//		cout<<"with len = "<<len<<endl;
				res = isSq(i+1, iniSq, len, len-1);
				fail = !res;
			}

		}
		//cout<<"res: "<<res<<endl;
		for (int i = 0; i < n; i++)
		{
		//	cout<<tab[i]<<endl;
			fail = fail || hasFail(tab[i]);
		}

		cout<<"Case #"<<test+1<<": ";

		if (res && !fail) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
	return 0;
}