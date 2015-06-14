#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int maxSuffix(string suf, string pre)
{
	int res = 0;
	if (pre.substr(0, suf.length()) == suf)
		res = suf.length();
	else
		res = maxSuffix(suf.substr(1), pre);
	return res;
}


int main()
{
	int nTest;

	cin>>nTest;

	while (nTest--)
	{
		string cad, last;
		int k, w;
		int res = 0;

		cin>>k>>w;

		last = "   ";
		for (int i = 0; i < w; i++)
		{
			cin>>cad;
			res += k-maxSuffix(last, cad);
			last = cad;
		}

		cout<<res<<endl;


	}

	return 0;
}