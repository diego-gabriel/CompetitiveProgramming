#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

map <int, vector<int> > tree;
vector <bool> vis;
vector <int> match;

int aug(int i){
	int res = 0;
	if (vis[i])
		res = 0;
	else{
		vis[i] = true;
		for (int j = 0; j < tree[i].size(); j++){
			int r = tree[i][j];
			if (match[r] == -1 || aug(match[r])){
				match[r] = i;
				res = 1;
				break;
			}
		}
	}
	return res;
}

int main(){
	int nTest;

	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		int n, m;
		cin>>n;
		int A[n];
		for (int i = 0; i < n; i++){
			cin>>A[i];
		}
		cin>>m;
		int B[m];
		for (int i = 0; i < m; i++){
			cin>>B[i];
		}
		tree.clear();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (A[i] != 0){
					if (B[j] == 0 || B[j] % A[i] == 0){
						tree[i].push_back(n+j);
					}
				}
				else{
					if (B[j] == 0){
						tree[i].push_back(n+j);
					}
				}
			}
		}

		int mcbm = 0;
		match.assign(n+m, -1);
		for (int i = 0; i < n; i++){
			vis.assign(n, false);
			mcbm += aug(i);
		}
		printf("Case %d: %d\n", test, mcbm);
	}
}