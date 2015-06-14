#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>


using namespace std;

struct NetConf
{
	int ip, mask;
	NetConf(){};
	NetConf(int a, int b){
		ip = a;
		mask = b;
	}
	int net(){
		return ip & mask;
	}
};

struct Computer
{
	vector <NetConf> nets;
	Computer(){};
	void read(){
		int a, b, c, d, e, f, g, h, n, ip, mask;
		scanf("%d\n", &n);
		while (n--){
			scanf("%d.%d.%d.%d %d.%d.%d.%d\n", &a, &b, &c, &d, &e, &f, &g, &h);

			ip = a<<24 | b<<16 | c<<8 | d;
			mask = e<<24 |f<<16 | g <<8 | h;
			nets.push_back(NetConf(ip, mask));
		}
	}	
	bool contains(int subnet){

		for (int i = 0, n= nets.size(); i < n; i++){
			if (nets[i].net() == subnet)
				return true;
		}
		return false;
	}

	bool connects(Computer &b){
		for (int i = 0, n = b.nets.size(); i < n; i++){
			if (contains(b.nets.at(i).net()))
				return true;
		}
		return false;
	}
};



int main(){
	int n;
	cin>>n;

	Computer computers[100];
	vector <int> g[100];
	int parent[100];
	for (int i = 0; i < n; i++){
		computers[i].read();
		parent[i] = i;
		for (int j = 0; j < i; j++){
			if (computers[i].connects(computers[j])){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}

	int origen, destino;
	scanf("%d %d\n", &origen, &destino);
	origen--;
	destino--;
	int dist[100];
	
	memset(dist, 0, sizeof(dist));
	queue<int> cola;
	cola.push(origen);
	dist[origen] = 1;
	int dest;
	while (!cola.empty()){
		origen = cola.front();
		cola.pop();
		for (int i = 0, h = g[origen].size(); i < h; i++){
			dest = g[origen][i];
			if (dist[dest] == 0){
				dist[dest] = dist[origen]+1;
				cola.push(dest);
				parent[dest] = origen;
			}
		}
	}

	if (dist[destino] != 0){
		printf("Yes\n");
		stack<int> pila;

		while (parent[destino] != destino){
			pila.push(destino);
			destino = parent[destino];
		}

		printf("%d", destino+1);

		while (!pila.empty()){
			printf(" %d", pila.top()+1);
			pila.pop();
		}
		printf("\n");
	}
	else
		printf("No\n");

	return 0;
}