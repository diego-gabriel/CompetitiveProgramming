#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	for (int test = 1; test <= n; test++){
		int v;
		cin>>v;
		cout<<"Caso #"<<test<<": ";
		if (v % 2 == 0 && v >= 4)
			cout<<v/2<<endl;
		else
			cout<<"Imposible"<<endl;
	}
	return 0;
}