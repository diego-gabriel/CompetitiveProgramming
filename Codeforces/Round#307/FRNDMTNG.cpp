#include <iostream>

using namespace std;

int main(){

	int n;
	cin>>n;

	while (n--){
		double T1, T2;
		cin>>T1>>T2;

		cout<<1.0/(T1*T2)<<endl;
	}

	return 0;
}