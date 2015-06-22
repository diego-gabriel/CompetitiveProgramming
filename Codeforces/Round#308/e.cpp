#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

string cad;
int ini, fin;

long long eval(int begin, int end){
	stack<long long> pila;
	long long res = 0;
	char op;
	long long d;
	pila.push(cad[begin]-'0');

	for(int i = begin+1; i < end; i += 2){

		op = cad[i];
		if (i+1 == ini){
			d = eval(ini, fin);
			i = fin-1;
		}
		else 
			d = cad[i+1]-'0';

		if (op == '+'){
			pila.push(d);
		} else {
			d *= pila.top();
			pila.pop();
			pila.push(d);
		}
	}

	while (!pila.empty()){
		res += pila.top();
		pila.pop();
	}

	return res;
}	

long long max(long long a, long long b){
	return a > b ? a : b;
}

int main(){
	cin>>cad;

	vector<int> p;
	cad = "1*"+cad+"*1";
	for(int i = 0, n = cad.size(); i < n; i++){
		if (cad[i]=='*')
			p.push_back(i);
	}
	ini = 1000000;
	fin = 1000000;
	int n = cad.length();
	long long res = eval(0, n);
	for(int i = 0; i < p.size(); i++){
		for(int j = i+1; j < p.size(); j++){
			ini = p[i]+1;
			fin = p[j]-1;
			
			res = max(res, eval(0, n));
		}
	}

	cout<<res<<endl;
	return 0;
}