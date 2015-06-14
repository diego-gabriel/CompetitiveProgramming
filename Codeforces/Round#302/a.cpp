#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	int n;
	string cad;
	cin>>n>>cad;

	set <char> l;
	for (int i = 0; i < cad.length(); i++){
		l.insert(cad[i]);
	}

	if (l.size() >= n){
		cout<<"YES";

		l.clear();
		int count = 0;
		for (int i = 0; i < cad.length(); i++){
			if (count == n)
				cout<<cad[i];
			else
			if (l.find(cad[i]) == l.end()){
				cout<<endl;
				cout<<cad[i];
				l.insert(cad[i]);
				count++;
			}
			else{
				cout<<cad[i];
			}
		}
		cout<<endl;

	}
	else
		cout<<"NO"<<endl;

	return 0;
}