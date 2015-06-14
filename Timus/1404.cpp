#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string cad;

	while(cin>>cad)
	{
		for (int i = 0; i < cad.length(); i++)
		{
			cad[i] -= 'a';
		}

		for (int i = cad.length()-1; i > 0; i--)
		{
			cad[i] = (26 + (cad[i] - cad[i-1])) % 26;
		}
		cad[0] = (26 + (cad[0] - 5)) % 26;
		for (int i = 0; i < cad.length(); i++)
			cad[i] += 'a';

		cout<<cad<<endl;
	}


	return 0;
}