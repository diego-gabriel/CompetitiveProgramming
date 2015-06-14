#include <iostream>

using namespace std;

bool estaEnRegla(int llama, int a, int paso)
{
	return llama >= a && (llama - a) % paso == 0;
}

int abs(int a)
{
	return a > 0 ? a : -a;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

bool pasa(int a, int b, int c, int d)
{
	return abs(a - c) % gcd(d, b) == 0;
}

bool pasaRegla(int ax, int ay, int bx, int by, int cx, int cy)
{
	return pasa (ax, ay, bx, by) || (pasa(ax, ay, cx, cy) && pasa(cx, cy, bx, by));
}


int main()
{
	string yes = "ola k ase";
	string no = "no";
	int ax, ay, bx, by, cx, cy, n, l1, l2;
	while (cin>>ax>>ay>>bx>>by>>cx>>cy && (ax || ay || bx || by ||cx || cy))
	{
		cin>>n;

		for (int i = 0; i < n; i++)
		{
			cin>>l1>>l2;

			if (estaEnRegla(l1, ax ay) && estaEnRegla(l2, ax, ay))
				cout<<yes<<endl;
			else
			if (estaEnRegla(l1, bx, by) && estaEnRegla(l2, bx, by))
				cout<<yes<<endl;
			else
			if (estaEnRegla(l1, cx, cy) && estaEnRegla(l2, cx, cy))
				cout<<yes<<endl;
			else
			if (estaEnRegla(l1, ax, ay) && estaEnRegla(l2, bx, by) && pasaRegla(ax, ay, bx, by, cx, cy))
				cout<<yes<<endl;
			else
			if (estaEnRegla(l1, ax, ay) && estaEnRegla(l2, cx, cy) && pasaRegla(ax, ay, cx, cy, bx, by))
				cout<<yes<<endl;
			else
			if (estaEnRegla(l1, bx, by) && estaEnRegla(l2, ax, ay) && pasaRegla(bx, by, ax, ay, cx, cy))
				cout<<yes<<endl;
			else
			if (estaEnRegla(l1, bx, by) && estaEnRegla(l2, cx, cy) && pasaRegla(bx, by, cx, cy, ax, ay))
				cout<<yes<<endl;
			else
			if (estaEnRegla(l1, cx, cy) && estaEnRegla(l2, ax, ay) && pasaRegla(cx, cy, ax, ay, bx, by))
				cout<<yes<<endl;
			else
			if (estaEnRegla(l1, cx, cy) && estaEnRegla(l2, bx, by) && pasaRegla(cx, cy, bx, by, ax, ay))
				cout<<yes<<endl;
			else cout<<"no"<<endl;


		}
	}
	return 0;
}