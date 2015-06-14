#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	string a, b;
	int test = 0;
	while (cin>>a>>b && (a != "END" || b != "END")){
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		test++;
		cout<<"Case "<<test<<":";
		if (a == b){
			cout<<" same"<<endl;
		}
		else cout<<" different"<<endl;
	}	
	return 0;
}