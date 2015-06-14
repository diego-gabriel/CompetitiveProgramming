#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <ctype.h>
#include <algorithm>

using namespace std;

vector <string> msg;
vector <string> dicc[17];
char m[26];

bool orden (string a, string b)
{
	return a.length() < b.length();
}

void split(string &cad)
{
	map <string, bool> in;
	string p = "";
	msg.clear();

	for (int i = 0; i < cad.length(); i++)
	{
		if (cad[i] == ' ')
		{
			if (p != "" && !in[p])
			{
				in[p] = true;
				msg.push_back(p);
			}
			p = "";
		}
		else
			p = p + cad[i];
	}
	if (p != "" && !in[p])
		msg.push_back(p);
}

bool match(int i)
{
	bool res = i == msg.size();

	if (!res)
	{
		int size = msg[i].length();
		int size2 = dicc[size].size();
		bool still;
		int c, k;
		char add[size];
		for (c = 0; c < size; c++)
			add[c] = m[msg[i][c] - 'a'];
		string tar;
		for (c = 0; c < size2 && !res; c++)
		{
			tar = dicc[size][c];
			still = true;
			char car;

			//cout<<"matching: " + msg[i] + " with " + tar<<endl;
			for (k = 0; k < size && still; k++)
			{
				if (m[msg[i][k] - 'a'] == '*' || m[msg[i][k] - 'a'] == tar[k])
				{
					m[msg[i][k] - 'a'] = tar[k];
				} else still = false;
			}

			if (still)
			{
				for (k = 0; k < size; k++)
					m[msg[i][k] - 'a'] = tar[k];
				res = match(i+1);
			}
			if (!res)
			{
				for (k = 0; k < size; k++)
					if (add[k] == '*')
						m[msg[i][k] - 'a'] = '*';
			}

		}
	}
//	cout<<"returning "<<res<<endl;
	return res;
}

int main()
{
	int n;

	while (cin>>n)
	{
		string cad;
		msg.clear();

		for (int i = 1; i < 17; i++)
			dicc[i].clear();

		for (int i = 0; i < n; i++)
		{
			cin>>cad;
			dicc[cad.length()].push_back(cad);
		}

		cin.ignore();
		while (getline(cin, cad))
		{
			for (int i = 0; i < 26; i++)
				m[i] = '*';
			split(cad);
			bool ok = false;
			ok = match(0);

			sort(msg.begin(), msg.end(), orden);

			if (!ok)
			{
				for (int i = 0; i < cad.length(); i++)
					cout<<(cad[i] == ' ' ? ' ' : '*');
				cout<<endl;
			}
			else
			{
				for (int i = 0; i < cad.length(); i++)
					cout<<(cad[i] == ' ' ? ' ' : m[cad[i] - 'a']);
				cout<<endl;
			}

		}
	}
	return 0;
}