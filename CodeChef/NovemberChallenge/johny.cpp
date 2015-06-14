#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int nTest;

	cin>>nTest;

	while (nTest--)
	{
		int n;
		cin>>n;

		int songs[n];

		for (int i = 0; i < n; i++)
		{
			cin>>songs[i];
		}

		int k;

		cin>>k;

		k = songs[k-1];

		sort(songs, songs + n);

		int i = 0;

		while (songs[i] != k)
			i++;

		cout<<i+1<<endl;
	}
	return 0;
}