#include <iostream>

using namespace std;

int main()
{
	int n;

	cin>>n;

	int w[n];
	int toPut = 0;

	for (int i = 0; i < n; i++)
	{
		cin>>w[i];
		toPut += w[i];
	}

	int currW = 0;
	bool canPut = true;

	while (toPut)
	{
		if (canPut && w[currW])
		{
			cout<<'P';
			w[currW]--;
			toPut--;
			canPut = false;
		}
		else
		{
			if (currW > 0 && w[currW-1] && w[currW-1] > 0)
			{
				cout<<'L';
				currW--;
			} else
			if (currW < n-1)
			{
				cout<<'R';
				currW++;
			}
			else
			{
				cout<<'L';
				currW--;

			}
			canPut = true;
		}

	}

	cout<<endl;


	return 0;
}