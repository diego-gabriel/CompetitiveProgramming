#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
	int a, b;
	Edge(){};
	Edge(int x, int y){
		a = x;
		b = y;
	}

	void print(int d){
		cout<<a+d<<" "<<b+d<<endl;
	}
};

int main(){
	int k;
	cin>>k;
	if (k == 1){
		cout<<"YES\n2 1\n1 2\n";
	}
	else
	if (k % 2 == 0)
		cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		vector <Edge> g;
		for (int node = 1; node <= k+1; node++){

			for (int next = (node < k ? (node % 2 == 1 ? node+2 : node+1) : node+1); next <= k+1; next++){
				g.push_back(Edge(node, next));
			}
			if (node < k)
				g.push_back(Edge(k+2, node));
		}

		cout<<2*k+4<<" "<<g.size()*2+1<<endl;

		for (int i = 0, n = g.size(); i < n; i++){
			g[i].print(0);
		}
		for (int i = 0, n = g.size(); i < n; i++){
			g[i].print(k+2);
		}
		cout<<k+2<<" "<<2*k+4<<endl;

	}
	return 0;
}