#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;

	vector <int> neg;
	int f;
	cin>>n;
	long long res = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin>>f;
		if (f < 0)
			neg.push_back(-f), sum += (-f);
	}

	sort(neg.begin(), neg.end());

	cin>>f;

	long long corr = 0;
	int size = neg.size();
	for (int i = 0; i < size; i++)
	{
		if (neg[i] - corr > 0)
		{
			if (size - i >= f)
			{
				res += f*(neg[i] - corr);
				corr += (neg[i] - corr);
			}
			else
			{

				res += (size-i)*(neg[i] - corr);
				corr += (neg[i] - corr);	
			}
		}
	}

	cout<<res<<endl;
	return 0;
}