#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string cad;
	int test = 0;
	while (cin>>cad && cad != "#"){
		test++;
		cout<<"Case "<<test<<": ";
		if (cad == "HELLO")
			cout<<"ENGLISH"<<endl;
		else
		if (cad == "HOLA")
			cout<<"SPANISH"<<endl;
		else
		if (cad == "HALLO")
			cout<<"GERMAN"<<endl;
		else
		if (cad == "BONJOUR")
			cout<<"FRENCH"<<endl;
		else
		if (cad == "CIAO")
			cout<<"ITALIAN"<<endl;
		else
		if (cad == "ZDRAVSTVUJTE")
			cout<<"RUSSIAN"<<endl;
		else
			cout<<"UNKNOWN"<<endl;

	}
	return 0;
}