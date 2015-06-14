#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	string cad;

	while (getline(cin, cad))
	{
		int nElem = 0;
		int pos = 0;
		int res = 0;
		char k;
		for (int i = 0; i < cad.length(); i++)
		{
			k = cad[i];
			if (k == ' ')
			{
				nElem++;
				pos = 0;
			}
			else
			{
				res += (nElem + pos + k - 'A'); 
				pos++;
			}
		}

		cout<<res<<endl;
	}
}