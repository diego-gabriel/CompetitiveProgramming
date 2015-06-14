#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;

	while(n--)
	{
		int t, na;

		cin>>t>>na;

		int minimo, maximo;
		int a;
		minimo = maximo = 0;
		while (na--)
		{
			cin>>a;
			minimo = max(minimo, min(a, t-a));
			maximo = max(maximo, max(a, t-a));
		}

		cout<<minimo<<" "<<maximo<<endl;

	}
	return 0;
}