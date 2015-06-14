#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

struct Comando
{
	char ID, l;
	int pos;

	Comando()
	{
	}

	Comando(char id, char le, int p)
	{
		ID = id;
		l = le;
		pos = p;
	}

	void print()
	{
		printf("%c%c%02d", ID, l, pos);
	}
};

int main()
{
	string cad1, cad2;

	while (cin>>cad1 && cad1 != "#")
	{
		cin>>cad2;

		int eDist[cad1.length() + 1][cad2.length() + 1];
		memset(eDist, 0, sizeof(eDist));

		for (int i = 1; i <= cad1.length(); i++)
		{
			eDist[i][0] = i;
		}

		for (int i = 1; i <= cad2.length(); i++)
		{
			eDist[0][i] = i;
		}

		for (int i = 1; i <= cad1.length(); i++)
		{
			for (int j = 1; j <= cad2.length(); j++)
			{
				int costo = (cad1[i-1] != cad2[j-1]);
				eDist[i][j] = min(eDist[i][j-1] + 1, min(eDist[i-1][j] + 1, eDist[i-1][j-1] + costo));
			}
		}

/*		for (int i = 0; i <= cad1.length(); i++)
		{
			for (int j = 0; j <= cad2.length(); j++)
			{
				cout<<" "<<eDist[i][j];
			}
			cout<<endl;
		}
*/


		int i, j;
		int dist;
		int del, ins, chg;
		int l1, l2;
		
		stack <Comando> pila;

		l1 = cad1.length();
		l2 = cad2.length();
		i = l1;
		j = l2;
		dist = eDist[i][j];

		while (j || i)
		{
			if (i == 0 && j > 0) 
			{
				del = 0x7fffffff;
				ins = eDist[i][j-1];
				chg = 0x7fffffff;
			}
			else
			if (j ==0 && i > 0) 
			{
				ins = 0x7fffffff;
				chg = 0x7fffffff;
				del = eDist[i-1][j];
			}
			else
			{
				del = eDist[i-1][j];
				ins = eDist[i][j-1];
				chg = eDist[i-1][j-1];
			}


			//Insercion
			if (ins < del && ins < chg)
			{
				pila.push(Comando('I', cad2[j-1], i));
				dist--;
				j--;
			}
			else
			if (del <= ins && del < chg)
			{
				pila.push(Comando('D', cad1[i-1], i));
				dist--;
				i--;
			}
			else
			{
				if (eDist[i][j] != chg)
				{
					pila.push(Comando('C', cad2[j-1], i));
					dist--;
				}
				i--;
				j--;
			}
		}

		i = 0; // este i cuenta las deformidades q sufre la cadena original
			   // en pocas ajusta el indice
		while (!pila.empty())
		{
			if (pila.top().ID == 'I') i++; //si es insersion recorre
			pila.top().pos += i;
			pila.top().print();
			if (pila.top().ID == 'D') i--; //si elimina, retrocede :D
			pila.pop();
		}

		printf("E\n");

	}
	return 0;
}