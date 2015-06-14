#include <iostream>

using namespace std;

int main()
{
	int n, d;
	cin>>n>>d;
	long long res = 0;
	int p[n];


	for (int i = 0; i < n; i++)
		cin>>p[i];

	if (n < 3) res = 0;
	else
	{
		int begin, end;

		begin = 0;
		end = 2;

		for (int i = 2; i < n; i++)
		{
			if (p[end] - p[begin] > d)
			{
		//		cout<<"calculando "<<begin<<" "<<end<<endl;
				long long r = end - begin;
		//		cout<<"resParcial: "<<((r-1)*(r-2)) / 2<<endl;
				res += ((r-1)*(r-2)) / 2;
				begin++;
				i--;
			}
			else
				end++;
		}
		long long r = end - begin;
		res += (r*(r-1)*(r-2)) / 6;
	}

	cout<<res<<endl;

	return 0;
}