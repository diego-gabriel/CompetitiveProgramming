#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

map <int, set<int> > tab, vis;
map <int, map<int, int> > dist;


bool exists(int x, int y){
	return tab.find(x) != tab.end() && tab[x].find(y) != tab[x].end();
}

bool visited(int x, int y){
	return vis.find(x) != vis.end() && vis[x].find(y) != vis[x].end();
}

void visit(int x, int y){
	vis[x].insert(y);
}

int main(){

	int x0, y0, x1, y1;
	int a, b, r;
	int n;

	cin>>x0>>y0>>x1>>y1>>n;
	for(int i = 0; i < n; i++){
		cin>>r>>a>>b;

		for(int k = a; k <= b; k++){
		//	cout<<r<<" "<<k;
			tab[r].insert(k);
		//	if (exists(r, k))
		//		cout<<"   ---> OK";
		//	cout<<endl;
		}
	}

	queue<pair<int, int> > cola;
	cola.push(make_pair(x0, y0));
	dist[x0][y0] = 0;
	int x, y;
	while (!cola.empty() && !visited(x1, y1)){
		x = cola.front().first;
		y = cola.front().second;
		//cout<<"on "<<x<< " "<<y<<endl;
		cola.pop();

		if (exists(x+1, y) && !visited(x+1, y)){
			cola.push(make_pair(x+1, y));
			visit(x+1, y);
			dist[x+1][y] = dist[x][y] + 1;
		//	cout<<"x+1"<<endl;
		}
		if (exists(x-1, y) && !visited(x-1, y)){
			cola.push(make_pair(x-1, y));
			visit(x-1, y);
			dist[x-1][y] = dist[x][y] + 1;
		//	cout<<"x-1"<<endl;
		}
		if (exists(x, y+1) && !visited(x, y+1)){
			cola.push(make_pair(x, y+1));
			visit(x, y+1);
			dist[x][y+1] = dist[x][y] + 1;
		//	cout<<"y+1"<<endl;
		}
		if (exists(x, y-1) && !visited(x, y-1)){
			cola.push(make_pair(x, y-1));
			visit(x, y-1);
			dist[x][y-1] = dist[x][y] + 1;
			//cout<<"y-1"<<endl;
		}
		if (exists(x+1, y+1) && !visited(x+1, y+1)){
			cola.push(make_pair(x+1, y+1));
			visit(x+1, y+1);
			dist[x+1][y+1] = dist[x][y] + 1;
		}
		if (exists(x+1, y-1) && !visited(x+1, y-1)){
			cola.push(make_pair(x+1, y-1));
			visit(x+1, y-1);
			dist[x+1][y-1] = dist[x][y] + 1;
		}
		if (exists(x-1, y+1) && !visited(x-1, y+1)){
			cola.push(make_pair(x-1, y+1));
			visit(x-1, y+1);
			dist[x-1][y+1] = dist[x][y] + 1;
		}
		if (exists(x-1, y-1) && !visited(x-1, y-1)){
			cola.push(make_pair(x-1, y-1));
			visit(x-1, y-1);
			dist[x-1][y-1] = dist[x][y] + 1;
		}
	}

	if (visited(x1, y1))
		cout<<dist[x1][y1]<<endl;
	else
		cout<<-1<<endl;
	return 0;
}