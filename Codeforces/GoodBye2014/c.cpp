#include <iostream>
#include <stack>

using namespace std;

int w[1000];

int quit(stack <int> &pila, int book){
	int res = 0;

	stack <int> aux;

	while (!pila.empty() && pila.top() != book){
		res += w[pila.top()];
		aux.push(pila.top());
		pila.pop();
	}
	if (!pila.empty())
		pila.pop();

	while (!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}
	pila.push(book);
	return res;
}

int main(){
	int n, m;
	cin>>n>>m;
	for (int i = 0; i < n; i++)
		cin>>w[i+1];
	int b[m];
	for (int i = 0; i < m; i++)
		cin>>b[i];

	stack <int> pila;
	int total = 0;
	for (int i = 0; i < m; i++){
		int book = b[i];
		total += quit(pila, book);
	}	

	cout<<total<<endl;
	return 0;
}