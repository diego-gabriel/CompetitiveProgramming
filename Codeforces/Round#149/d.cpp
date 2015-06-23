#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > g;

int main(){
	int n, m;
	cin>>n>>m;
	g.assign(n+5, vector<int>());
	int o,d;
	for(int i = 0; i < m; i++){
		cin>>o>>d;
	//	cout<<"read> "<<o<<" "<<d<<endl;
		g[o].push_back(d);
		g[d].push_back(o);
	}

	int count[n+1];
	memset(count, 0, sizeof(count));

	queue<int> cola;
	vector<int> res;
	int a;
	for(int i = 1; i <= n; i++){
		cin>>a;
		if(a == 0)
			cola.push(i);
		count[i] = a;
	}

	int bot;
	while (!cola.empty()){
		bot = cola.front();
		cola.pop();	
	//	cout<<"actual> "<<bot<<endl;
		count[bot]--;
		res.push_back(bot);
		for(int i = 0, l = g[bot].size(); i < l; i++){
			count[g[bot][i]]--;
			if (count[g[bot][i]] == 0){
				cola.push(g[bot][i]);
		//		cout<<"pushed: "<<g[bot][i]<<endl;
			}
		//	cout<<" count: "<<g[bot][i]<<" is "<<count[g[bot][i]]<<endl;
		}
	}

	cout<<res.size()<<endl;
	if (res.size() > 0){

		cout<<res[0];
		for(int i = 1, l = res.size(); i < l; i++){
			cout<<" "<<res[i];
		}
		cout<<endl;
	}
	return 0;
}