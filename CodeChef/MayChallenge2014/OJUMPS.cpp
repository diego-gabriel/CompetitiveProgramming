#include <iostream>

using namespace std;

int main(){

	unsigned long long a;
	cin>>a;
	unsigned long long mod = a % 6;
	if (mod == 1 || mod == 3 || mod == 0)
		cout<<"yes"<<endl;
	else 
		cout<<"no"<<endl;

	return 0;
}
