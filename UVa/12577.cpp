#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string cad;
	int test = 0;
	while (cin>>cad && cad != "*"){
		test++;
		cout<<"Case "<<test<<": ";
		if (cad == "Hajj")
			cout<<"Hajj-e-Akbar"<<endl;
		else
			cout<<"Hajj-e-Asghar"<<endl;
	}
	return 0;
}