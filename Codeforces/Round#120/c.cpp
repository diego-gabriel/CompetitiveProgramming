#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>	
#include <queue>	

using namespace std;


int main(){
	int n;

	string cad;
	cin>>n;
	stack<int> pila;
	bool fst = true;
	bool ok = true;
	queue<string> res;
	while (cin>>cad){
		if (!fst && pila.empty()){
			ok = false;
		}
		fst = false;
		if(cad == "pair"){
			res.push(cad);
			res.push("<");
			pila.push(2);
		} else {
			if (!pila.empty() && pila.top() == 2){

				res.push(cad);
				res.push(",");
				int t = pila.top();
				pila.pop();
				pila.push(t-1);
			}
			else if(!pila.empty() && pila.top() == 1){
				res.push(cad);
				while (!pila.empty() && pila.top() == 1){
					res.push(">");
					pila.pop();
				}
				if (!pila.empty() && pila.top() == 2){
					res.push(",");
					int t = pila.top();
					pila.pop();
					pila.push(t-1);		
				}
			}
			else if(pila.empty()){
				res.push(cad);
			}
		}
	}

	if (ok && pila.empty()){
		while(!res.empty()){
			cout<<res.front();
			res.pop();
		}
		cout<<endl;
	}
	else
		cout<<"Error occurred"<<endl;

	return 0;
}