#include <iostream>
#include <set>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int m;
	int v;
	cin>>m;
	multiset<int> s;
	queue<int> c;
	for (int i = 0; i < m-1; i++){
		scanf("%d", &v);
		s.insert(v);
		c.push(v);
	}

	while (scanf("%d", &v) && v != -1){
		s.insert(v);
		c.push(v);

		printf("%d\n", *(s.rbegin()));
		int e = c.front();
		c.pop();
		s.erase(s.find(e));
	}

	return 0;
}