#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;

	bool bitH[m];
	bool bitV[n];

	for (int i = 0; i < m; i++)
		bitH[i] = false;
	for (int i = 0; i < n; i++)
		bitV[i] = false;
	
	bool b;

	for (int k = 0; k < n; k++)
		for (int i = 0; i < m; i++)
		{
			cin>>b;
			bitV[k] = bitV[k] | b;
			bitH[i] = bitH[i] | b;
		}

	if (bitH[0] || bitH[m-1] || bitV[0] || bitV[n-1]) cout<<2<<endl;
	else cout<<4<<endl;
	return 0;
}
