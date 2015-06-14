#include <iostream>

using namespace std;

int main(){
	int n, k;
	cin>>n>>k;

	if (k > (n*n+1)/2){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		bool car = true;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){

				if (car && k){
					cout<<"L";
					k--;
				}
				else
					cout<<"S";
				car = !car;
			}
			if (n % 2 == 0)
				car = !car;
			cout<<endl;
		}
	}
	return 0;
}