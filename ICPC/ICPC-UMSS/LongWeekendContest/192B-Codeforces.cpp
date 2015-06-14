#include <iostream>

using namespace std;

int main()
{
	int n;
	
	cin>>n;
	
	int last1, last2, it;
	
	cin>>it;
	n--;
	
	last1 = last2 = it;
	int a;
	
	if (n){
		for (int i = 0; i < n; i++)
		{
			cin>>it;
			it = min(it, max(last1, last2));
			last2 = last1;
			last1 = it;
		}
		
	}
	cout<<last1<<endl;
	
	return 0;
}
