#include <iostream>
#include <cstdio>

using namespace std;

int parent[10000+5];

int find_parent(int a){
	return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
}

void init (int n){
	for (int i = 0; i < n; i++)
		parent[i] = i;
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		init(n+1);
		int s[n+1];

		for (int i = 0; i < n; i++)
			scanf("%d", &s[i+1]);

		int nq;
		scanf("%d", &nq);

		while (nq--){
			int k, x, y;
			scanf("%d", &k);

			if (k == 0){
				scanf("%d %d", &x, &y);

				int ownerX, ownerY;
				ownerX = find_parent(x);
				ownerY = find_parent(y);
				if (ownerX == ownerY)
					printf("Invalid query!\n");
				else{
					if (s[ownerX] > s[ownerY])
						parent[ownerY] = ownerX;

					if (s[ownerY] > s[ownerX])
						parent[ownerX] = ownerY;
				}
			} else {
				scanf("%d", &y);
				printf("%d\n", find_parent(y));
			}	
		}

	}
	return 0;
}