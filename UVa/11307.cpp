#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <vector <int> > graph;
vector <vector<int> > memo;
const int MAX_COLOR = 20;

int solve(int node, int color){
//	cout<<"??"<<endl;
	if (memo[node][color] == -1){
		int res = 0x0fffffff;

		if (graph[node].size() == 0) //is a leaf
			res = color;
		else{

				res = color;
			for (int i = 0; i < graph[node].size(); i++){
				int next = graph[node][i];
				int best = 0x0fffffff;
				for (int aColor = 1; aColor < MAX_COLOR; aColor++){
					if (color != aColor){
						best = min(best, solve(next, aColor));
					}
				}
				res += best;
			}
		}


		memo[node][color] = res;
	}
	return memo[node][color];
}

vector <int> parse(string cad){
	int buff = 0;
	bool ok = false;
	vector <int> res;
	for (int i = 0; i < cad.length(); i++){
		char k = cad[i];
		if (k == ' '){
			if (ok){
				res.push_back(buff+1);
			}
			ok = false;
			buff = 0;
		}
		else{
			buff *= 10;
			buff += k - '0';
			ok = true;
		}
	}
/*	cout<<"for: " + cad + "parsed: ";
	for (int i = 0; i < res.size(); i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;*/
	return res;
}

int main(){
	int n;
	while (cin>>n && n){
		graph.clear();
		graph.assign(n+1, vector<int>());
		memo.clear();
		memo.assign(n+1, vector<int>(MAX_COLOR, -1));
		vector <int> p(n+1);

		for (int i = 0; i <= n; i++){
			p[i] = i;
		}
		string noSense;
		for (int i = 0; i < n; i++){
			int parent;
			scanf("%d:", &parent);
			getline(cin, noSense);
			vector<int> children = parse(noSense + " ");
			graph[parent+1] = children;
			for (int j = 0; j < children.size(); j++){
				p[children[j]] = parent+1;
			}
		}
		int root = 1;
		while (p[root] != root)
			root = p[root];
		graph[0].push_back(root);

		cout<<solve(0, 0)<<endl;

	}
	return 0;
}