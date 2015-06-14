#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <ctype.h>

using namespace std;

#define DEF "**************************"

vector <string> msg;
vector <string> dicc[17];



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



string match (int c, string &curMatch)
{
	if (c == msg.size())
		return curMatch;
	else
	{
		int size, sizeDicc, i, k;
		string newMatch, tar;
		size = msg[c].size();
		sizeDicc = dicc[size].size();
		bool stillOk = false;

		for (i = 0; i < sizeDicc && !stillOk; i++)	
		{
			newMatch = curMatch;
			tar = dicc[size][i];
			stillOk = true;

			for (k = 0; k < size && stillOk; k++)
			{
				char car = msg[c][k] - 'a';
				if (newMatch[car] == '*' || newMatch[car] == tar[k])
				{
					newMatch[car] = tar[k];
				}
				else{
					stillOk = false;	
				} 
			}

			
			if (stillOk)
			{
				newMatch = match(c+1, newMatch);
				if (newMatch != "")
				{
					return newMatch;
				}
				else stillOk = false;
			}
		}
	}
	return "";
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
			split(cad);
			string res;
			string empty = DEF;
			res = match(0, empty);
			if (res == "") res = DEF;

			for (int i = 0; i < cad.length(); i++)
				cout<<(cad[i] == ' ' ? ' ' : res[cad[i] - 'a']);
			cout<<endl;
		

		}
	}
	return 0;
}