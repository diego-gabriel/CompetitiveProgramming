#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string cad;
	cin>>cad;
	
	long long res = 0;
	long long h;
	string sub;
	h = 0;
	
	for (int i = 0; i < int(cad.length()) - 4; i++)
	{
		sub = cad.substr(i,5);
		if (sub == "heavy")
			h++, i+= 4;
		if (sub == "metal")
			res += h, i+= 4;
	}
	cout<<res;
	
	return 0;
}
