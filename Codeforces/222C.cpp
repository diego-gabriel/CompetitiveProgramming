#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <set> 
#include <algorithm>

using namespace std;

bool des (int a, int b)
{
	return a > b;
}

bool asc (int a, int b)
{
	return a < b;
}

int main()
{
	multiset <int> final;
	vector <int> tour1, tour2;
	multiset <int> :: iterator it;
	int n, x;
	int val;

	cin>>n>>x;

	for (int i = 0; i < n; i++)
	{
		cin>>val;
		tour1.push_back(val);
	}
	for (int i = 0; i < n; i++)
	{
		cin>>val;
		tour2.push_back(val);
	}

	sort(tour1.begin(), tour1.end(), des);
	sort(tour2.begin(), tour2.end(), des);

	for (int i = 0; i < n; i++)
	{
		final.insert(tour1[i] + tour2[i]);
	}


	int worst = n;

	it = final.begin();


	while (*it < x && it != final.end())
	{
		it++;
		worst--;
	}
	cout<<1<<" "<<worst<<endl;
	return 0;
}



