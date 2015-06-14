#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

string reverse(string cad)
{
	string res = "";
	for (int i = cad.length()-1; i >= 0; i--)
		res = res + (cad[i] == ')' ? '(' : '[');
	return res;
}

int main()
{
	char k;
	string res = "";
	int best = 0;
	int act = 0;
	stack <char> pila;
	string bestRes = "";
	bool rev = true;
	string toReverse = "";
	while (cin>>k)
	{
		cout<<"leido: "<<k<<endl<<res<<endl<<bestRes<<endl;;
		if (k == ')' || k == ']')
		{
			if (!pila.empty())
			{
				if (k == ')' && pila.top() == '(')
				{
					
					toReverse = toReverse + ")";
					pila.pop();
				}
				else
				if (k == ']' && pila.top() == '[')
				{
					toReverse = toReverse + "]";
					act++;	
					pila.pop();
				}
				else	
				{
					while (!pila.empty())
						pila.pop();
					if (act > best)
					{
						cout<<"ouch"<<endl;
						res = res + reverse(toReverse) + toReverse;
						bestRes = res;
						best = act;
						toReverse = "";
						rev = false;
					}	
					act = 0;
					res = "";
				}


				if (pila.empty())
				{
					cout<<"vacia" + toReverse<<endl;
					res = res + reverse(toReverse) + toReverse;
					toReverse = "";
				}
			}
		}

		if (k == '(' || k == '[')
		{
			pila.push(k);
		}
	}
	
	if (act > best)
	{
		cout<<"ouch"<<endl;
		res = res + reverse(toReverse) + toReverse;
		bestRes = res;
		best = act;
		toReverse = "";
		rev = false;
	}	

	cout<<best<<endl;
	cout<<bestRes<<endl;

	return 0;
}