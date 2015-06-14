#include <iostream>
#include <stack>

using namespace std;

#define RED true
#define BLACK false

int fill(int x, stack<int> &pila){
	int dist = 0;
//	cout<<"enter with: "<<x<<endl;
	while (x){
		pila.push(x);
//		cout<<"pushed: "<<x<<endl;
		x/=2;
		dist++;
	}
//	cout<<"lala -- fin"<<endl;
	return dist;
}

int lca_a(stack<int> &a, stack<int> &b, int &dist){
	int lca = 1;

	dist = 0;
	while (!a.empty() && !b.empty() && a.top() == b.top()){
		lca = a.top();
		dist++;
		a.pop();
		b.pop();
	}
//	cout<<"lca -- fin "<<lca<<endl;
	return lca;
}

int main(){
	int q;
	cin>>q;
	bool root = BLACK;
	while (q--){
		string cad;
		int x;
		int y;
		cin>>cad;
		if (cad[1] == 'i'){
			root = !root;
		}
		else{
			cin>>x>>y;

			int lca, dist_x, dist_y, dist_lca;
			stack<int> pila_x, pila_y;
			dist_x = fill(x, pila_x);
			dist_y = fill(y, pila_y);
			lca = lca_a(pila_x, pila_y, dist_lca);
			int dist = dist_x + dist_y - 2*dist_lca +1;
//			cout<<"dist_x "<<dist_x<<endl;
//			cout<<"dist_y "<<dist_y<<endl;
//			cout<<"dist_lca "<<dist_lca<<endl;
//			cout<<"DIST: "<<dist<<endl;
			int cant_b, cant_r;
			if (dist_x % 2 == 1){
				if (root == RED){
//					cout<<"is red"<<endl;

					cant_r = (dist+1)/2;
					cant_b = dist - cant_r;
				}
				else{
//					cout<<"is black"<<endl;
					cant_b = (dist+1)/2;
					cant_r = dist - cant_b;
				}
			}
			else{

				if (root == BLACK){
//					cout<<"is red"<<endl;

					cant_r = (dist+1)/2;
					cant_b = dist - cant_r;
				}
				else{
//					cout<<"is black"<<endl;
					cant_b = (dist+1)/2;
					cant_r = dist - cant_b;
				}	
			}

			if (cad[1] == 'r')
				cout<<cant_r<<endl;
			else 
				cout<<cant_b<<endl;

		}
	}
	return 0;
}