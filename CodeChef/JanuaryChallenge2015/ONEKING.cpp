#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct Limit
{
	int id;
	bool begin;

	Limit(){}
	Limit(int a, bool b){
		id = a;
		begin = b;
	}

	bool start(){
		return begin;
	}
	bool end(){
		return !begin;
	}
};

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		bool detoned[n];
		stack<Limit> field[2001];
		int a,b;
		for (int i = 0; i < n; i++){
			scanf("%d %d", &a, &b);
			field[a].push(Limit(i, true));
			field[b].push(Limit(i, false));
			detoned[i] = false;
		}

		int res = 0;
		int acum = 0;
		stack <int> det;
		for (int i = 0; i <= 2000; i++){
			bool boom = false;
			while (!field[i].empty()){
				Limit l = field[i].top();
				field[i].pop();

				if (l.start()){
					acum++;
					det.push(l.id);
				}

				if (l.end() && !detoned[l.id]){
					boom = true;
				}
			}

			if (boom){
				res++;
				while (!det.empty()){
					detoned[det.top()] = true;
					det.pop();
				}
			}
		}

		printf("%d\n", res);

	}
	return 0;
}