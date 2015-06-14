#include <iostream>

using namespace std;

inline int min(int a, int b){
	return a < b ? a : b;
}

int main(){
	int a, b;
	while(cin>>a>>b && a != -1 && b != -1){
		cout<<min((100+b-a)%100, (100-b+a)%100)<<endl;
	}
	return 0;
}