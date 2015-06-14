#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	while (n--){
		string cad;
		cin>>cad;
		stack<char> pila;
		int res = 0;
		int pre = 0;
		bool valid = true;
		for (int i = 0; i < cad.length() && valid; i++){
			char k = cad[i];
			if (k == '<') pila.push(k);
			else
			{
				valid = !pila.empty();
				if (valid) pila.pop();
				if (valid && pila.empty()) res = i+1;
			}
		}

		cout<<res<<endl;
	}
	return 0;
}