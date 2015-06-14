#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int nTest;
	cin>>nTest;

	while(nTest--){
		int b, p;
		cin>>b>>p;
		int product;
		int total = 0;
		for (int i = 0; i < p; i++){
			cin>>product;
			if (total + product <= b)
				total += product;
		}
		cout<<total<<endl;
	}
	return 0;
}