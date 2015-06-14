#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	while (cin>>t){
		int count = 0;
		int v;
		string cad;
		for (int i = 0; i < t; i++){
			cin>>cad;
			if (cad == "donate"){
				cin>>v;
				count += v;
			}
			else
				cout<<count<<endl;
		}
	}
	return 0;
}