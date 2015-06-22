#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int a[100][100];

	int x, y, x2, y2;

	int n;
	cin>>n;
	int res = 0;
	memset(a, 0, sizeof(a));
	while (n--){
		cin>>x>>y>>x2>>y2;
		res += ((x2-x+1)*(y2-y+1));
	}	
	cout<<res<<endl;
	return 0;
}