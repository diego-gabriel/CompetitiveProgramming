#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	int max = 100000;
	cout<<max<<endl;

	for (int i = 0; i < max; i++)
	{
		cout<<rand() % 100 + 1<<" ";
	}
	cout<<endl;

	cout<<max<<endl;

	for (int i = 0; i < max; i++)
	{
		int l, r;
		l = rand() % 100 + 1;

		do
		{
			r = rand() % 100 + 1;

		} while (r < l);

		cout<<l<<" "<<r<<" "<<rand() % 1000000000 + 1<<endl;
	}
}