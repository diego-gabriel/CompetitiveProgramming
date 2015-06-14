#include <cstring>
#include <iostream>

using namespace std;

int n;

struct Nodo
{
	string tok;
	Nodo* fst;
	Nodo* scd;
	bool ok;
	Nodo()
	{
		tok = "";
		fst = scd = NULL;
		ok = true;
	}
	
	Nodo (string cad)
	{
		tok = cad;
		if (tok == "pair")
		{
			ok = (cin>>cad && n);
			fst = new Nodo (cad);
			if (!ok)
			fst = new Nodo();
			ok = (cin>>cad && n);
			cout<<"scd"<<endl;
			scd = new Nodo (cad);
			if (!ok)
			scd = new Nodo();
			ok = (ok || !n )&& (*fst).ok && (*scd).ok;
		}
		else {
			fst = scd = NULL;
			ok = true;
			n--;
			cout<<n<<endl;
		}
		
	}
	
	void print()
	{
		
		cout<<tok;
		if (tok == "pair")
			cout<<"<";
			fst->print();
			cout<<",";
			scd->print();
			cout<<">";
	}
	
};

int main()
{
	cin>>n;
	
	string cad;
	cin>>cad;
	
	Nodo res = Nodo(cad);
	if (res.ok)
		res.print();
	else cout<<"Error ocurred";
	cout<<endl;
	return 0;
}
