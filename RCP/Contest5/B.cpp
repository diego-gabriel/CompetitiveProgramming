#include <iostream>

using namespace std;

int main(){
	int a, b, c;
	cin>>a>>b>>c;
	if (b > (c-a))
		cout<<"Hunters win!"<<endl;
	else
		cout<<"Props win!"<<endl;

	return 0;
}