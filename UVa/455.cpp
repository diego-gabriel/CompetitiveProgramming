#include <iostream>
#include <cstring>

using namespace std;

string sub(string &cad, int top)
{
	string res = "";

	for (int i = 0; i < top; i++)
		res = res + cad[i];

	return res;
}

bool isPeriodic(string &cad, int i)
{
	bool res = (cad.length() % i) == 0;

	if (res)
	{
		string period = sub(cad, i);
		string aux = "";

		for (int k = 0; k < cad.length() / i; k++)
			aux = aux + period;

		res = cad == aux;

	}

	return res;
}

int main()
{
	int n;
	cin>>n;
	bool first = true;
	while(n--)
	{
		if (!first) cout<<endl;

		string cad;
		cin>>cad;

		int i = 1;

		while (!isPeriodic(cad, i))
			i++;

		cout<<i<<endl;

		first = false;
	}
	return 0;
}