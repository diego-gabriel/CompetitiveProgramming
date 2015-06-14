#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int top;
	cin>>top;

	int l, r;

	cin>>l>>r;
	set <int> face;
	face.insert(7-top);
	face.insert(top);
	for (int i = 1; i < n; i++)
	{
		cin>>r>>l;
		face.erase(r);
		face.erase(7-r);
		face.erase(l);
		face.erase(7-l);
	}

	if (face.empty()) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;

	return 0;
}