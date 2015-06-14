#include <iostream>

using namespace std;

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int k, n, w;
	cin>>k>>n>>w;

	int tot = k*((w*(w+1))/2);

	cout<<max(0, tot-n)<<endl;

	return 0;
}