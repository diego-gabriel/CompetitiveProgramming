#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <set>
#include <algorithm>


using namespace std;

vector <int> visited;
vector <vector <int> > graph;
int colorCount[2];
int n;
struct Point
{
	double x, y;
	int id;
	Point(){
	}
	Point(double a, double b){
		x = a;
		y = b;
	}
	Point(bool a, int i){
		scanf("%lf %lf\n", &x, &y);
		id = i;
	}

	double dist(Point aPoint){
		double i = x - aPoint.x;
		double j = y - aPoint.y;
		return sqrt(i*i + j*j);
	}
};

bool operator < (Point a, Point b){
	if (a.x == b.x){
		return a.y < b.y;
	}
	return a.x < b.x;
}


set<Point> backup;
vector<Point> points;

void addAllNeigthbours(Point &aPoint){
	for (int i = -5; i <= 5; i++){
		for (int j = -5; j <= 5; j++){
			Point otherPoint = Point(aPoint.x+i, aPoint.y+j);
			if (aPoint.dist(otherPoint) <= 5 && backup.find(otherPoint) != backup.end()){
				graph[aPoint.id].push_back(backup.find(otherPoint)->id);
			}
		}
	}
}

void buildGraph(){
	for (int i = 0; i < n; i++){
		addAllNeigthbours(points[i]);
	}
}

void dfs(int node, bool color){
	colorCount[color]++;
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++){
		if (!visited[graph[node][i]])
			dfs(graph[node][i], !color);
	}
}

int main(){
	int a;
	while (scanf("%d\n", &n) == 1){
		points.clear();
		backup.clear();
		graph.clear();
		graph.assign(n, vector<int>());
		Point aPoint;
		for (int i = 0; i < n; i++){
			aPoint = Point(true, i);
			points.push_back(aPoint);
			backup.insert(aPoint);
		}
		memset(colorCount, 0, sizeof(colorCount));
		visited.clear();
		visited.assign(n, false);
		buildGraph();
		int res = 0;
		for (int i = 0; i < n; i++){
			if (!visited[i]){
				colorCount[0] = colorCount[1] = 0;
				dfs(i, false);
				res = res + min(colorCount[0], colorCount[1]);
			}
		}

		printf("%d\n", res);
	}
	return 0;
}