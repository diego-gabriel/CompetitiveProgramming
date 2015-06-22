#include <iostream>
#include <stack>
#include <queue>
#include <set>

using namespace std;

struct Data
{
	bool q;
	bool s;
	bool p;

	stack<int> pila;
	queue<int> cola;
	multiset<int> pcola;

	Data(){
		q = s = p = true;
	}

	void push(int x){
		if (q)
			cola.push(x);
		if (s)
			pila.push(x);
		if (p)
			pcola.insert(x);
	}

	void pop(int x){
		if (q){
			//cout<<"poping "<<x<<" from "<<"cola "<<cola.size()<<endl;
			q = !cola.empty();
			if (q && x == cola.front())
				cola.pop();
			else
				q = false;
			//cout<<q<<endl;
		}
		if (s){
			//cout<<"poping "<<x<<" from "<<"pila "<<pila.size()<<endl;
			s = !pila.empty();
			if (s && x == pila.top())
				pila.pop();
			else
				s = false;
			//cout<<s<<endl;
		}
		if (p){
			//cout<<"poping "<<x<<" from "<<"pq "<<pcola.size()<<endl;
			p = !pcola.empty();
			if (p && x == *(--pcola.end())){
				//cout<<"aca"<<endl;
				//cout<<pcola.size()<<endl;
				pcola.erase(--pcola.end());
				//cout<<"paso"<<endl;
			}
			else
				p = false;
			//cout<<p<<endl;
		}
	}

	string veredict(){
		int tot = s + p + q;
		string res;
		if (tot > 1)
			res = "not sure";
		if (tot == 0)
			res = "impossible";
		if (tot == 1){
			if (s)
				res = "stack";
			if (q)
				res = "queue";
			if (p)
				res = "priority queue";
		}
		return res;
	}
};

int main(){
	int n;
	while (cin>>n){
		Data d;

		int p, x;

		while (n--){
			cin>>p>>x;

			if (p == 1){
				d.push(x);
			}
			else
				d.pop(x);
		}

		cout<<d.veredict()<<endl;
	}
	return 0;
}