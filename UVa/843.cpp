#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <cstdio>
#include <vector>

using namespace std;

set <char> posb[17][30];
map <string, string> match;
map <char, char> carMatch;
map <char, bool> hasMatch;
map <char, set <int> > diccOc, msgOc;
string msj;
map <char, set<char> > posMatch;

void init()
{
	for (int k = 1; k < 17; k++)
	{
		for (int i = 0; i < 'z' - 'a'; i++)
			posb[k][i].clear();
	}
}

void split(string cad, vector <string> &vec)
{
	string s = "";
	vec.clear();
	for (int i = 0; i < cad.length(); i++)
	{
		if (cad[i] == ' ' && s != "")
		{
			vec.push_back(s);
			s = "";
		}
		else
		{
			s = s + cad[i];
		}
	}

	if (s != "")
		vec.push_back(s);
}

bool isSubset (set <int> &d, set <int> &m)
{
	set<int> :: iterator it, i, f;

	f = d.end();
	i = m.end();

	bool ok = true;

	for (it = m.begin(); it != i && ok; it++)
	{
		ok = d.find(*it) != f;
	}

	return ok;
}

void compare(string a, string b)
{
	int len = a.length();
	for (int i = 0; i < len; i++)
	{
		if (!hasMatch[a[i]] && carMatch[b[i]] == 0 && isSubset(msgOc[b[i]], diccOc[a[i]]))
			posb[len][b[i] - 'a'].insert(a[i]);
	}
}

void compare(set <string> &dic, set <string> &msg)
{
	set <string> :: iterator it, that;

	for (it = dic.begin(); it != dic.end(); it++)
	{
		for (that = msg.begin(); that != msg.end(); that++)
		{
			compare(*it, *that);
		}
	}
}

void mostrar()
{
	set <char> :: iterator it;
	long long tam = 0;

	for (int k = 1; k < 17; k++)
	{
		cout<<"palabras de longitud "<<k<<":"<<endl;
		long long t = 1;
		for (int i = 0; i < 'z' - 'a'; i++)
		{
			t = t * (posb[k][i].size() > 0 ? posb[k][i].size() : 1);
			cout<<"Posibilidades de "<<(char(i + 'a'))<<":"<<endl;

			for (it = posb[k][i].begin(); it != posb[k][i].end(); it++)
				cout<<*it<<endl;
		}

		cout<<"    Complejidad parcial: O("<<t<<")"<<endl;
		tam += t;
	}

	cout<<"Complejidad: O("<<tam<<")"<<endl;
}

void prepOc(const string &cad, map <char, set <int> > &m)
{
	for (int i = 0; i < cad.length(); i++)
		m[cad[i]].insert(i);
}

int main()
{
	int n;

	while (cin>>n)
	{
		set <string> dicc[17], msg[17];
		vector <string> mensaje;
		init();
		string cad;

		for (int i = 0; i < n; i++)
		{
			cin>>cad;
			prepOc(cad, diccOc);
			dicc[cad.length()].insert(cad);
		}


		cin.ignore();
		while (getline(cin, cad))
		{
			init();
			match.clear();
			msgOc.clear();
			hasMatch.clear();
			posMatch.clear();
			carMatch.clear();
			split(cad, mensaje);
			msj = cad;
			for (int i = 0; i < 17; i++)
			{
				msg[i].clear();
			}

			for (int i = 0; i < mensaje.size(); i++)
			{
				msg[mensaje[i].length()].insert(mensaje[i]);
				prepOc(mensaje[i], msgOc);
			}

			for (int i = 1; i < 17; i++)
			{
				compare(dicc[i], msg[i]);
				for (char k = 'a'; k < 'z'; k++)
				{
					if (posb[i][k - 'a'].size() == 1)
					{
						carMatch[k - 'a'] = *posb[i][k - 'a'].begin();
						hasMatch[carMatch[k - 'a']] = true;
					}
				}
			}

			mostrar();

			for (int i = 1; i < 17; i++)
			{
				for (char k = 'a'; k < 'z'; k++)
				{
					set <char> :: iterator b, f;

					b = posb[i][k - 'a'].begin();
					f = posb[i][k - 'a'].end();

					while (b != f)
					{
						//RECOGER TODOS LOS POSIBLES MATCH

						b++;
					}
				}
			}



		}
	}
	return 0;
}