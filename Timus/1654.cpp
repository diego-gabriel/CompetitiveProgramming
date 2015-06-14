#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>

using namespace std;

int main(){
	string cad;
	cin>>cad;
	cad = cad;
	
	stack<char>  pila, res;
	for (int i = 0, n = cad.length(); i < n; i++){
		if (!pila.empty() && pila.top() == cad[i])
			pila.pop();
		else
			pila.push(cad[i]);
	}

	while(!pila.empty()){
		res.push(pila.top());
		pila.pop();
	}

	while (!res.empty()){
		printf("%c", res.top());
		res.pop();
	}
	cout<<endl;
	return 0;
}