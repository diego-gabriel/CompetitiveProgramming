#include <iostream>
#include <cstring>

using namespace std;

int f(string cad){
	int res = 0;
	int max_res = 0;
	for (int i = 0; i < cad.size(); i++){
		if (cad[i] == '(')
			res++;
		else
			res--;

		max_res = max_res < res ? res : max_res;
	}

	return max_res;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		string cad;
		cin>>cad;
		int p = f(cad);
		for (int i = 0; i < p; i++)
			cout<<'(';
		for (int i = 0; i < p; i++)
			cout<<')';
		cout<<endl;

	}
	return 0;
}