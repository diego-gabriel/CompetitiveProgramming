#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	cin>>a>>b>>c;

	int r1, r2, r3;
	r1 = 0;

	while (r1 <= a)
	{
		r2 = b - r1;
		r3 = c - r2;

		if (r1 + r3 == a && r1 + r2 == b && r2 + r3 == c)
			break;
		r1++;
	}

	if (r1 <= a)
		cout<<r1<<" "<<r2<<" "<<r3<<endl;
	else cout<<"Impossible"<<endl;
	return 0;
}