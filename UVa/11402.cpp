#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string pirates;


struct Nodo
{
	int low, high;
	Nodo* izq;
	Nodo* der;
	int buc;
	int bar;
	int op;

	Nodo (){};
	Nodo (int min, int max)
	{
		op = 0;
		low = min;
		high = max;

		if (low == high)
		{
			buc = pirates[low] == '1';
			bar = pirates[low] == '0';
		}
		else
		{
			int mid = (low + high) / 2;

			izq = new Nodo(low, mid);
			der = new Nodo(mid + 1, high);

			buc = izq -> buc + der -> buc;
			bar = izq -> bar + der -> bar;
		}
	}

	void apply(int opID)
	{
		switch (opID)
		{
			case 1: {
				op = 1;
			} break;
			case 2: {
				op = 2;
			}
			case 3: {
				if (op == 3)
					op = 0;
				else
					op = op == 0 ? 3 : (op == 1 ? 2 : 1);
			}
		}
	}

	void applyOp (int opID, int min, int max)
	{
		if (low == min && high == max){
			apply(opID);
			op = 0;	
		} 
		else
		{
			int mid = (low + high) / 2;
			if (max <= mid) {

				der -> applyOp(op, min, max);
				izq -> applyOp(opID, min, max);

				op = 0;
			}
			else
				if (mid < min){

					izq -> apply(op);
					der -> applyOp(opID, min, max);
					op = 0;	
				} 
			else
			{
				izq -> applyOp(opID, min, mid);
				der -> applyOp(opID, mid + 1, max);
				op = 0;
			}
		}
	}

	void makeOp(int min, int max)
	{
		if (low == high)
		{
			if (op == 3)
				swap(buc, bar);
			if (op == 1)
				buc = 1, bar = 0;
			if (op == 2)
				bar = 1, buc = 0;

		}
		else
		{
			int mid = (min + max) / 2;

			izq -> applyOp(op, min, mid);
			der -> applyOp(op, mid + 1, max);

			buc = izq -> buc + der -> buc;
			bar = izq -> bar + der -> bar;
		}		
	}

	int consultar (int min, int max)
	{
		int res = 0;

		cout<<min<<" <consultando arbol> "<<max<<endl;
		cout<<low<<" <consultando arbol this> "<<high<<endl;

		if (low == min && high == max)
		{	
	//		cout<<"finished"<<endl;
			if (op != 0)
			{
				makeOp(min, max);
				op = 0;
			}
			res = buc;
		} 
		else
		{
			int mid = (low + high) / 2;
			int left, rigth;

			cout<<"mid: "<<mid<<endl;
			if (max <= mid) {
				cout<<"izq"<<endl;
				der -> applyOp(op, min, mid);
				res = izq -> consultar(min, mid);
			}
			else
				if (mid < min) {
					cout<<"der"<<endl;
					izq -> applyOp(op, mid + 1, max);
					res = der -> consultar(mid + 1, max);
				}
			else {
				cout<<"both"<<endl;
				der -> applyOp(op, min, mid);
				izq -> applyOp(op, mid + 1, max);
				left = izq -> consultar(min, mid);
				rigth = der -> consultar(mid + 1, max);

				res = left + rigth;
			}

		}

		return res;
	}

} segmentTree;


void readInputString()
{
	int t;
	cin>>t;
	pirates = "";
	string aux;
	while (t--)
	{
		int n;
		cin>>n;
		cin>>aux;
		for (int i = 0; i < n; i++)
		{
			pirates = pirates + aux;
		}
	}
}

void readQuerys()
{
	int nQuery;
	int godQuery = 1;
	cin>>nQuery;

	char op;
	int low, high;

	for (int q = 0; q < nQuery; q++)
	{
		cin>>op>>low>>high;
	//	cout<<"making nQuery"<<endl;
		switch (op)
		{
			case 'F': {segmentTree.applyOp(1, low, high); break;}
			case 'E': {segmentTree.applyOp(2, low, high); break;}
			case 'I': {segmentTree.applyOp(3, low, high); break;}
			case 'S': {
				cout<<"Q"<<godQuery<<": "<<segmentTree.consultar(low, high)<<endl;
				godQuery++;
			} 

		}
	}
}


int main()
{
	int nTest;

	cin>>nTest;

	for (int test = 1; test <= nTest; test ++)
	{	
		cout<<"Case "<<test<<":"<<endl;
		readInputString();
		segmentTree = Nodo(0, pirates.size()-1);
	//	cout<<"tree maked"<<endl;
		readQuerys();
	}

	return 0;
}