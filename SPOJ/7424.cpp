#include <iostream>

using namespace std;

int main(){
	int a, b;
	while (cin>>a>>b && a != -1 && b != -1){
		if (a < b)
			swap(a, b);
		cout<<(a+b)/(b+1)<<endl;
	}
	return 0;
}