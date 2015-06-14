#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int parent[100000+5];

int find_parent(int a){
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
}

void init(int n){
	for (int i = 0; i <= n; i++)
		parent[i] = i;
}

int abs(int a){
	return a < 0 ? -a : a;
}

int main(){
	int n, k, p;
	cin>>n>>k>>p;
	vector <pair<int, int> > pos;
	int a, b, p1, p2, d;

	init(n);
	for (int i = 1; i <= n; i++){
		cin>>d;
		pos.push_back(make_pair(d, i));
	}

	sort(pos.begin(), pos.end());

	for (int i = 1; i < pos.size(); i++){
		if ((pos[i].first - pos[i-1].first) <= k){
			parent[pos[i].second] = parent[pos[i-1].second];
		}
	}
	/*for (int i = 1; i <= n; i++){
		cout<<i<<" -> "<<parent[i]<<endl;
	}*/

	for (int i = 0; i < p; i++){
		cin>>a>>b;
		p1 = find_parent(a);
		p2 = find_parent(b);

		if (p1 == p2) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}