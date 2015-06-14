#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > graph;
vector <vector<int> > memo;
const int MAX_COLOR = 20;

int solve(int node, int color){
	//cout<<"enter: "<<node<<" with: "<<color<<endl;
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
				//cout<<"best for node: "<<next<<" is "<<best<<endl;
				res += best;
			}
		}


		memo[node][color] = res;
	}
//	cout<<node<<" & "<<color<<endl;
//	cout<<"return: "<<memo[node][color]<<endl;
	return memo[node][color];
}


int main(){
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		int n;
		cin>>n;
		graph.clear();
		graph.assign(n+1, vector<int>());

		memo.clear();
		memo.assign(n+1, vector <int> (MAX_COLOR, -1));

		int p;
		for (int i = 1; i <= n; i++){
			cin>>p;
			graph[p].push_back(i);
		}

		cout<<"Case #"<<test<<": "<<solve(0, 0)<<endl;

	}
	return 0;
}