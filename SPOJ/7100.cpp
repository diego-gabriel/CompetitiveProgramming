#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


struct Point
{
	int x, y;
	Point(){}
	Point(int a, int b){
		x = a;
		y = b;
	}

	void read(){
		cin>>x>>y;
	}
	void print(){
		cout<<x<<" "<<y;
	}
};

bool operator < (Point a, Point b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

Point operator - (Point a, Point b){
	return Point(a.x - b.x, a.y - b.y);
}

int operator * (Point a, Point b){
	return a.x*b.y - a.y*b.x;
}
struct Arista
{
	Point origen, destino;
	Arista(){}
	Arista(Point o, Point d){
		origen = o;
		destino = d;
		if (destino < origen)
			swap(origen, destino);
	}
};



map <Point, set<Point> > grafo;
map <Point, map<Point, bool> > valido;
map <Point, bool> vis;
void add(Arista a){
	if (valido.find(a.origen) != valido.end() && valido[a.origen].find(a.destino) != valido[a.origen].end()){
		valido[a.origen][a.destino] = false;
		grafo[a.origen].erase(a.destino);
		grafo[a.destino].erase(a.origen);

	}
	else{
		valido[a.origen][a.destino] = true;
		
	}
}

void dfs(Point origen){
	cout<<" ";
	origen.print();
	vis[origen] = true;

	set<Point> :: iterator it;
	Point destino;

	for (it = grafo[origen].begin(); it != grafo[origen].end(); it++){
		destino = *it;

		if (!vis[destino])
			dfs(destino);
	}
}


int main(){
	int n, x, y;
	while(cin>>n && n != -1){
		grafo.clear();
		valido.clear();
		vis.clear();

		for(int i = 0; i < (n-2); i++){
			Point a, b, c;
			a.read();
			b.read();
			c.read();

			grafo[a].insert(b);
			grafo[b].insert(a);

			grafo[b].insert(c);
			grafo[c].insert(b);

			grafo[c].insert(a);
			grafo[a].insert(c);

			add(Arista(a, b));
			add(Arista(c, b));
			add(Arista(a, c));

		}
		Point inicio = grafo.begin()->first;
		inicio.print();
		vis[inicio] = true;

		set<Point> :: iterator it = grafo[inicio].begin();
		Point first = *it;
		it++;
		Point second = *it;

		if ((first - inicio) * (second - inicio) > 0)
			inicio = second;
		else
			inicio = first;


		dfs(inicio);

		cout<<endl;
	}
		
	return 0;
}
