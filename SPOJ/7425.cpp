#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int memo[3010][3010];
int parent[3010];

void init(int c){
	for (int i = 0; i < c+10; i++){
		parent[i] = i;
		for (int j = 0; j < c+10; j++)
			memo[i][j] = 0;
	}
}

int find_parent(int a){
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
}

struct Arista
{
	int peso, destino;
	Arista(){};
	Arista(int a, int b){
		destino = a;
		peso = b;
	}
};


struct Link
{
	int origen, destino;
	int peso;
	Link(){};
	Link(int a, int b, int c){
		origen = a;
		destino = b;
		peso = c;
	}

	void print(){
		cout<<origen<<" -> "<<destino<<" : "<<peso<<endl;
	}
};

vector<vector<Arista> > grafo;

Link readLink(){
	int a, b, c;
	cin>>a>>b>>c;
	return Link(a, b, c);
}

bool orden(Link a, Link b){
	return a.peso < b.peso;
}

int min(int a, int b){
	return a < b ? a : b;
}

vector <bool> vis;

void dfs(int origen, int x){
	//cout<<"dfs on : "<<origen<<endl;
	vis[origen] = true;

	for (int i = 0; i < grafo[origen].size(); i++){
		int destino = grafo[origen][i].destino;
		int peso = grafo[origen][i].peso;
	//	cout<<"trying to go to: "<<destino<<endl;
		if (!vis[destino]){
	//		cout<<"ok, go"<<endl;
			memo[x][destino] = max(memo[x][origen], peso);
			dfs(destino, x);
		}
	}

}

void solve(int origen){
	vis.clear();
	vis.assign(3010, false);
	memo[origen][origen] = 0; 
	dfs(origen, origen);
}

int main(){
	int c, h, l;

	while (cin>>c>>l>>h){
		if (c == -1 && h == -1 && l == -1)
			break;
		init(c);
		vector <Arista> aux;
		vector <Link> links;
		grafo.clear();
		grafo.assign(c+1, aux);
		Link link;

		int origen, destino, peso;
		for (int i = 0; i < l; i++){
			link = readLink();
			links.push_back(link);
		}

		sort(links.begin(), links.end(), orden);

		int in = 1;
		vector <Link> :: iterator it;
		it = links.begin();
		vector <Link> mst;
		while (in < c){
			link = *it;
			it++;

			int p1, p2;
			p1 = find_parent(link.origen);
			p2 = find_parent(link.destino);

			if (p1 != p2){
				parent[p1] = p2;
				in++;
				mst.push_back(link);
			}
		}

	//	for (int i = 0; i < mst.size(); i++)
	//		mst[i].print();
		//cout<<"mst done!"<<endl;


		for (it = mst.begin(); it != mst.end(); it++){
			link = *it;
			grafo[link.origen].push_back(Arista(link.destino, link.peso));
			grafo[link.destino].push_back(Arista(link.origen, link.peso));
		}

		//cout<<"ini"<<endl;
		for (int i = 1; i <= c; i++){
			solve(i);
		}
		//cout<<"lala"<<endl;

		cin>>origen>>destino;
	//	cout<<"from: "<<origen<<" to "<<destino<<endl;
		cout<<memo[origen][destino];
		for (int i = 1; i < h; i++){
			cin>>origen>>destino;
	//		cout<<endl<<"from: "<<origen<<" to "<<destino<<endl;
		
			cout<<" "<<memo[origen][destino];

		}
		cout<<endl;
	}
}