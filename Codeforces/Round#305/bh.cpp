#include <iostream>

using namespace std;

int main(){
	int n, m, q;
	n = 500;
	m = 500;
	q = 5000;

	cout<<n<<" "<<m<<" "<<q<<endl;

	for (int i = 0; i < 500; i++){
		cout<<0;
		for (int j = 1; j < 500; j++)
			cout<<" "<<j%2;
		cout<<endl;
	}


	for (int i = 0; i < 5000; i++){
		cout<<i%500+1<<" "<<(500-i%500)<<endl;
	}
	return 0;
}