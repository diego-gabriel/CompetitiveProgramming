#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
pair<int, int> n1[100000];
pair<int, int> n2[100000];

bool orden(pair <int, int> a, pair <int, int> b)
{
	return 
}


int main()
{
	cin>>n>>m;
	
	for (int i = 0; i < n; i++)
		cin>>n1[i].first, n1[i].second = i;
	for (int i = 0; i < n; i++)
		cin>>n2[i].first, n2[i].second = i;
	
	sort(n1, n1 + n, orden);
	
	
	return 0;
}
