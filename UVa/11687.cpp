#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string cad;
	while (cin>>cad && cad != "END"){
		if (cad.length() >= 10)
			cout<<4<<endl;
		else
		if (cad == "1"){
			cout<<1<<endl;
		}
		else
		if (cad.length() == 1)
			cout<<2<<endl;
		else cout<<3<<endl;
	}
}