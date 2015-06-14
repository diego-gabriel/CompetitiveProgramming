#include <iostream>

using namespace std;

int main()
{
	double a, b, c;
	
	cin>>a>>b>>c;
	
	double res;
	
	res = (c*(a-b) + b-1) / b;
	
	cout<<int(res);
	
	return 0;
}
