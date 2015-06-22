#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

string a, b;
vector<queue<char> > res;

void solve(int i, int current, stack<char> pila, queue<char> cola){
	stack<char> np= pila;
	queue<char> nc= cola;
	if (i < a.length()){
		pila.push(a[i]);
		cola.push('i');
		solve(i+1, current, pila, cola);
	}
	if (!np.empty() && np.top() == b[current]){
		np.pop();
		nc.push('o');
		if (current+1 == b.length())
			res.push_back(nc);
		else
			solve(i, current+1, np, nc);
	}
}


int main(){
	while(cin>>a>>b){
		res.clear();
		queue<char> v;
		stack<char> s;
		solve(0, 0, s, v);

		cout<<'['<<endl;
		for(int i = 0, n = res.size(); i < n; i++){
			cout<<res[i].front();
			res[i].pop();
			while(!res[i].empty()){
				cout<<' '<<res[i].front();
				res[i].pop();
			}
			cout<<endl;
		}
		cout<<']'<<endl;
	}

	return 0;
}