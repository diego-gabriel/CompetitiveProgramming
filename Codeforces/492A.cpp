#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int s = 0;
	int i = 1;
	int res = 0;
	int a = 0;
	while (s + a <= n){
		s += a;
		a += i;
		i++;
		res++;
	}

	cout<<res-1<<endl;


	return 0;
}