#include <iostream>

using namespace std;

int main(){
	int a, b, r;
	cin>>a>>b>>r;

	if (r*2 <= a && r*2 <= b)
		cout<<"First"<<endl;
	else
		cout<<"Second"<<endl;

	return 0;
}