#include <iostream>
#include <cstring>
#include <set>
#include <stack>

using namespace std;

bool eval(string cad){
	stack<char> pila;
	bool res = true;

	for(int i = 0; i < cad.size() && res; i++){
		if (cad[i]=='(')
			pila.push(cad[i]);
		else{
			res = !pila.empty() && pila.top() == '(';
			if (res)
				pila.pop();
		}
	}

	return res && pila.empty();
}	

int main(){
	int t;
	cin>>t;
	while(t--){
		string cad;
		int k;
		cin>>cad>>k;
		if (eval(cad)){

		} else {
			if (k > 1)
				cout<<-1<<endl;
			else
				cout<<cad<<endl;
		}

	}
	return 0;
}