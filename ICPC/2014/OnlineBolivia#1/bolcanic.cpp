#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

int memo[100005];
int move[105];
int n, m;

bool win(bool player, int c){
	for (int i = 0; i < m; i++){
		if (c - move[i] < 0)
			continue;
		int next = c - move[i];
		if (next == 0)
			return player;
		if (memo[next] != 0){
			if (memo[next] == 1) return player;
			continue;
		}
		memo[next] = win(!player, next) == player ? 1 : 2;
		if (memo[next] == 1) return player;

	}
	return !player;
}

int main(){
	int nTest;
	scanf("%d", &nTest);

	for (int test = 1; test <= nTest; test++){

		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++)
			scanf("%d", &move[i]);
		for (int i = 0; i <= n+2; i++){
			memo[i] = 0;
		}
		printf("Caso #%d: ", test);
		if (win(true, n))
			printf("SI\n");
		else
			printf("NO\n");

	}
	return 0;
}