#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
	int id;
	int u, v;

	Edge(){}
	Edge(int a, int b, int c){
		id = a;
		u = b;
		v = c;
	}
};

struct Point
{
	int id;
	int x, y;
	Point(){}
	Point(int c, int a, int b){
		x = a;
		y = b;
		id = c;
	}
};

bool operator < (Point a, Point b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

vector <int> tree[1510];
Point p[1510];

int main(){
	int n;
	cin>>n;
	int o, d;

	for (int i = 0; i < n-1; i++){
		cin>>o>>d;
		tree.push_back(Edge(i, o-1, d-1));
	}


	for(int i = 0; i < n; i++){
		cin>>o>>d;
		v[i] = Vertex(o, d);
	}

	return 0;
}