#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<char> v;
	for (int i = 0; i < n; i++)
		v.push_back('(');
	for (int i = 0; i < n; i++)
		v.push_back(')');

	bool fst = true;
	do{

		stack <char> pila;

		for (int i = 0; i < 2*n; i++){
			if (v[i] == '(')
				pila.push('(');
			else{
				if (!pila.empty())
					pila.pop();
			}
		}

		if (pila.empty()){
			for (int i = 0; i < n*2; i++)
				cout<<v[i];
			cout<<endl;
		}
	}while(next_permutation(v.begin(), v.end()));

	return 0;
}