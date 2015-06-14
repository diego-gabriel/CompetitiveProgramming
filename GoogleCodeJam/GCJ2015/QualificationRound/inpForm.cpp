#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	string cad;
	int n;
	cin>>n;
	cin.ignore();
	while (n--){
		getline(cin, cad);
		getline(cin, cad);
		cout<<cad<<endl;
	}


	return 0;
}