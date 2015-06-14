#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	
	int min = n + (m - n> 0 ? m - n : 0);
	int max = n + (m - 1 > 0 ? m - 1 : 0);
	
	if (n == 0 && m != 0) cout<<"Impossible"<<endl;
	else cout<<min<<" "<<max<<endl;
	
	return 0;
}
