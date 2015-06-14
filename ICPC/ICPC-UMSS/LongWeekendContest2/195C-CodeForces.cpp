#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int n;

vector <string> separar (string cad)
{
	vector <string> res;
	
	if (cad != "")
	{
		while(!cad.empty() && cad[0] != 't' && cad[0] != 'c') cad.erase(cad.begin());
		
	}
	
	if (!cad.empty())
	switch (cad[1])
	{
		case 'r': res.push_back("try"); break;
		case 'h': {
					string ex = "";
					while (cad[0] != '(') cad.erase(cad.begin());
					while (!isupper(cad[0]) && !islower(cad[0])) cad.erase(cad.begin());
					
					while (isupper(cad[0]) || islower(cad[0]))
					{
						ex += cad[0];
						cad.erase(cad.begin());
					}
					res.push_back("throw");
					res.push_back(ex);
				  } break;
		case 'a': {
					string ex, msg;
					ex = msg = "";
					
					while (cad[0] != '(') cad.erase(cad.begin());
					while (!isupper(cad[0]) && !islower(cad[0])) cad.erase(cad.begin());
					
					while (isupper(cad[0]) || islower(cad[0]))
					{
						ex += cad[0];
						cad.erase(cad.begin());
					}
					
					while (cad[0] != '\"') cad.erase(cad.begin());
					cad.erase(cad.begin());
					
					
					while (cad[0] != '\"')
					{
						msg += cad[0];
						cad.erase(cad.begin());
					}
					
					res.push_back("catch");
					res.push_back(ex);
					res.push_back(msg);
					
				  } break;
	}
	return res;
}

struct Operador
{
	string ID;
	string val;
	
	Operador ()
	{
		ID = val = "";
	}
	Operador (string a, string b)
	{
		ID = a;
		val = b;
	}
	
};

int main()
{
	cin>>n;
	
	string cad;
	bool ok = false;
	string res = "Unhandled Exception";
	
	stack <Operador> cola;
	cin.ignore();
	while (n--)
	{
		getline(cin, cad);
		vector <string> tokens = separar(cad);
		if (!tokens.empty())
		{
			if (tokens[0] == "try")
				cola.push(Operador ("try", "")); //, cout<<"try ins"<<endl;
			if (tokens[0] == "throw")
				cola.push(Operador (tokens[0], tokens[1]));//, cout<<"throw ins"<<endl;
			if (tokens[0] == "catch")
			{
				Operador op = cola.top();
				cola.pop();
				//cout<<"OP: "<<op.ID<<endl;
				if (op.ID == "throw")
				{
					cola.pop();
					if (op.val == tokens[1])
					{
						if (!ok)
						{
							//cout<<"=O"<<endl;
							res = tokens[2];
							ok = true;
						}	
					}
					else
					{
						cola.push(op);
					}
				}
			}
			
		}
	}
	
	cout<<res<<endl;
	
	return 0;
}
