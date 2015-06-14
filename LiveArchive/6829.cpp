#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <vector <int> > tree;
vector <int> parent;
vector <int> climb;
vector <bool> visit;

struct Answer
{
	int back, stay;
	Answer(){
		back = 0;
		stay = 0;
	};
	Answer(int a, int b){
		back = a;
		stay = b;
	}

	int dif(){
		return back - stay;
	}
};

bool isLeaf(int node){
	return tree[node].size() == 0;
}

Answer solve(int node){
	Answer res;

	if (visit[node]){
		Answer biggerDif;

		for (int i = 0; i < tree[node].size(); i++){
			Answer aux = solve(tree[node][i]);
			res.back += aux.back;
			if (aux.dif() > biggerDif.dif())
				biggerDif = aux;	
		}
		res.stay = res.back - biggerDif.dif();
		res.back += climb[node];

	}

	return res;
}

void goUp(int node){
	if (!visit[node]){
		visit[node] = true;
		goUp(parent[node]);
	}
}

int main(){
	int n, f;
	while (cin>>n>>f){
		tree.assign(n+1, vector<int>());
		climb.assign(n+1, 0);
		visit.assign(n+1, false);
		parent.assign(n+1, 0);

		int o, d, p;
		for (int i = 0; i < n-1; i++){
			cin>>o>>d>>p;
			tree[o].push_back(d);
			climb[d] = p;
			parent[d] = o;
		}

		for (int i = 0; i < f; i++){
			cin>>o;
			goUp(o);
		}


		Answer ans = solve(1);
		cout<<ans.stay<<endl;
	}	
	return 0;
}