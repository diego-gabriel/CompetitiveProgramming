#include <iostream>

using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){

	double a, b;

	while (cin>>a>>b && (a != -1 && b != -1)){
		if (a*37 == 1000*b)
			cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}