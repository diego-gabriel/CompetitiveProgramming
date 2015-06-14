#include <iostream>

using namespace std;

int main(){
	int n;
	int test = 0;
	while (cin>>n && n){
		test++;
		cout<<"Case "<<test<<": ";
		int a, b, c;
		a = b = 0;
		for (int i = 0; i < n; i++){
			cin>>c;

			if (c == 0)
				b++;
			else a++;
		}	

		cout<<a-b<<endl;
	}
	return 0;
}