#include <iostream>

using namespace std;

int main()
{
	int x, y, r;
	cin>>x>>y>>r;
	r*=2;
	
	if (x >= r && y >= r) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	
	return 0;
}
