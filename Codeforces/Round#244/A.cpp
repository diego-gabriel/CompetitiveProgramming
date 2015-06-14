#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int nPolices = 0;
	int v;
	int crimes = 0;
	while(n--){
		cin>>v;
		if (v == -1){
			if (nPolices)
				nPolices--;
			else crimes++;
		}
		else nPolices+=v;
	}

	cout<<crimes<<endl;
	return 0;
}