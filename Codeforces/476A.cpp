#include <iostream>

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;

	int res = 0;

	int a = 0;

	while((((n-a+1)/2 + a) % m) != 0 && a <= n){
		a++;
	}


	if (a > n)
		cout<<-1<<endl;
	else cout<<a+((n-a+1)/2)<<endl;

	return 0;
}