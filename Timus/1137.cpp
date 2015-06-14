#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <set>
#include <stack>

using namespace std;

int s;
stack <int> res;
vector<map <int, bool> > used(10005);
vector<int> g[10005];
vector<int> outs(10005, 0);

int bestOf(int &node){
	int res;
	int bc = 0;
	for (int i = 0, n = g[node].size(); i < n; i++){
		//cout<<node<<" "<<g[node][i]<<endl;
		if (!used[node][g[node][i]]){
			return g[node][i];
		}
	}
	return res;
}

void dfs(int node){
	if (outs[node] != 0){
		int best = bestOf(node);
		used[node][best] = true;
		outs[node]--;
		dfs(best);
	}
	res.push(node);
	s++;
}

int main(){
	int n, k, o, d;
	s = 0;
	scanf("%d\n", &n);
	int tot = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &k);
		tot += k;
		scanf(" %d", &o);

		for (int j = 0; j < k; j++){
			scanf(" %d", &d);
			outs[o]++;
			g[o].push_back(d);
			o = d;
		}
	}


	res.push(d);
	vector <int> vec;
	while(!res.empty()){
		d = res.top();
		res.pop();
		if (outs[d] > 0){
			dfs(d);
		} else {
			vec.push_back(d);
		}

	}

	printf("%d", (int)vec.size()-1);
	for (int i = 0, n = vec.size(); i < n; i++){
		printf(" %d", vec[i]);
	}
	printf("\n");

	return 0;
}