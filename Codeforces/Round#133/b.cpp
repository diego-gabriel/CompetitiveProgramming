#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool vis[200];
int parent[200];
int nout[200];
int find_parent(int a){
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
}

int main(){
	int n, m;
	cin>>n>>m;


	for(int i = 0; i < n; i++){
		parent[i+1] = i+1;
		nout[i+1] = 0;
	}

	for(int i = 0; i < m; i++){
		int a, b;
		cin>>a>>b;
		parent[find_parent(a)] = find_parent(b);
		nout[a]++;
		nout[b]++;
	}

	int res = 0;
	int bench = 0;

	for(int i = 1; i <= n; i++){
		find_parent(i);
	}
	for(int i = 1; i <= n; i++){
		if(parent[i] != -1){
			int id = parent[i];
			int size = 0;
			bool line = nout[i] == 0;
			//cout<<"new id found: "<<id<<endl;
			for(int j = 1; j <= n; j++){
				if (parent[j] != id)
					continue;

				line = line || (nout[j] == 1);
				size++;
				parent[j] = -1;
			}

			if(line){
			//	cout<<"was line "<<size<<endl;
				bench += size%2;
			} else {

			//	cout<<"was cicle "<<size<<endl;
				res += size%2;
			}
		}

	}

	cout<<res+(bench%2)<<endl;

	return 0;
}