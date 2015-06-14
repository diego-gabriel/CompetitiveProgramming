#include <iostream>

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;

	int rmin;
	int rmax;

	if (n == 0){
		if (m > 0)
			cout<<"Impossible"<<endl;
		else
			cout<<"0 0"<<endl;
	}
	else {
		if (n < m){
			rmin = n+(m-n);
			rmax = n+m-1;
		} else {
			rmin = n;
			rmax = n+m-1;
		}

		if (m == 0)
			rmax = n;
		cout<<rmin<<" "<<rmax<<endl;
	}
	return 0;
}