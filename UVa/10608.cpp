#include <iostream>
#include <map>

using namespace std;

int parent[30300];

void init(int n){
	for (int i = 0; i < n+5; i++)
		parent[i] = i;
}

int find_parent(int a){
	return parent[a] == a ? a: parent[a] = find_parent(parent[a]);
}

int main(){
	int nTest;
	cin>>nTest;

	while (nTest--){
		int n, m;
		cin>>n>>m;
		init(n);
		int a, b;
		for (int i = 0; i < m; i++){
			cin>>a>>b;
			parent[find_parent(a)] = find_parent(b);
		}

		map <int, int> f;
		int res = 0;
		int id = 0;
		for (int i = 1; i <= n; i++){
			f[find_parent(i)]++;
			if (f[find_parent(i)] > res){
				res = f[find_parent(i)];
			}
		}
		cout<<res<<endl;
	}
	return 0;
}