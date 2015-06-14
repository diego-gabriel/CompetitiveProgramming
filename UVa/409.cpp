#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <cstdio>
#include <ctype.h>

using namespace std;

set <string> keywords;

void toLowerCase(string &cad)
{
	for (int i = 0; i < cad.length(); i++)
		cad[i] = tolower(cad[i]);
}

int getNumberOfk(string cad)
{
	int res = 0;
	char k;
	toLowerCase(cad);
	string pal = "";

	for (int i = 0; i < cad.length(); i++)
	{
		k = cad[i];
		if (islower(k)) pal = pal + k;
		else
		{
			if (pal != "")
			{
				if (keywords.find(pal) != keywords.end())
					res++;
				pal = "";
			}
		}
	}
	if (pal != "" && keywords.find(pal) != keywords.end())
	{
		res++;
		pal = "";
	}

	return res;
}

int main()
{
	int k, e;
	int test = 0;
	while (cin>>k>>e)
	{
		test++;
		string key;
		keywords.clear();

		for (int i = 0; i < k; i++)
		{
			cin>>key;
			keywords.insert(key);
		}

		cin.ignore();

		string ex;
		vector <string> res;
		int max = 0;
		int nOf;
		for (int i = 0; i < e; i++)
		{
			getline(cin,ex);
			nOf = getNumberOfk(ex);

			if (nOf == max)
			{
				res.push_back(ex);
			}

			if (nOf > max)
			{
				res.clear();
				res.push_back(ex);
				max = nOf;
			}

		}

		cout<<"Excuse Set #"<<test<<endl;

		for (int i = 0; i < res.size(); i++)
			cout<<res[i]<<endl;
		cout<<endl;

	}
	return 0;
}