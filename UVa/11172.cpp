#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	while (n--){
		long long a, b;
		cin>>a>>b;
		if (a < b)
			cout<<"<"<<endl;
		if (a == b)
			cout<<"="<<endl;
		if (a > b)
			cout<<">"<<endl;
	}
	return 0;
}