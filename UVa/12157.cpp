#include <iostream>

using namespace std;

int fMile(int d){
	return ((d+30)/30) * 10;
}
int fJuice(int d){
	return ((d+60)/60) * 15;
}

int main(){
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		cout<<"Case "<<test<<": ";
		int n;
		cin>>n;
		int mile, juice, d;
		mile = juice = 0;
		for (int i = 0; i < n; i++){
			cin>>d;
			mile += fMile(d);
			juice += fJuice(d);
		}

		if (mile == juice)
			cout<<"Mile Juice "<<mile<<endl;
		if (mile < juice)
			cout<<"Mile "<<mile<<endl;
		if (mile > juice)
			cout<<"Juice "<<juice<<endl;
	}
	return 0;
}