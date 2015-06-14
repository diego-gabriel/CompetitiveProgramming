#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int color[n+1];

	set<int> ady[n+1];
	set<int> :: iterator it;
	for (int i = 1; i <= n; i++){
		int v;
		color[i] = -1;
		while (scanf("%d", &v) && v != 0){
			ady[i].insert(v);
			ady[v].insert(i);
		}
	}


	queue <int> cola;
	cola.push(1);
	color[1] = 0;
	int origen;
	int destino;
	bool ok = true;
	while(!cola.empty() && ok){
		origen = cola.front();
		cola.pop();

		for(it = ady[origen].begin(); it != ady[origen].end() && ok; it++){
			if (color[*it] == -1){
				color[*it] = 1 - color[origen];
				cola.push(*it);
			}
			else{
				ok = color[origen] != color[*it];
			}
		}
	}

	if (ok)
		for (int i = 1; i <= n; i++)
			printf("%d", color[i]);
	else
		printf("-1");
	printf("\n");

	return 0;
}