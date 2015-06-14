#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool overOf(int a, int b){
	return a == b-1;
}

bool aboveOf(int a, int b){
	return a-1 == b;
}

bool isPossible(vector <int> stack, vector<int> current, int bottom, int top){
	bool res = true;
	while (top > bottom && res){
		if (aboveOf(stack[top], current[0])){
			current.insert(current.begin(), stack[top]);
			top--;
		}
		else
		if (aboveOf(stack[bottom], current[0])){
			current.insert(current.begin(), stack[bottom]);
			bottom++;
		}
		else
		if (overOf(stack[top], current[current.size()-1])){
			current.push_back(stack[top]);
			top--;
		}
		else
		if (overOf(stack[bottom], current[current.size()-1])){
			current.push_back(stack[bottom]);
			bottom++;
		}
		else
			res = false;
	}

	return res;
}

int main(){
	int nTest;
	scanf("%d", &nTest);

	for (int test = 1; test <= nTest; test++){
		int n;
		scanf("%d", &n);
		vector<int> stack;
		int v;
		for (int i = 0; i < n; i++){
			scanf("%d", &v);
			stack.push_back(v);
		}
		vector<int> att1, att2;
		att1.push_back(stack[0]);
		att2.push_back(stack[n-1]);
		printf("Case #%d: ", test);
		if (isPossible(stack, att1, 1, n-1) || isPossible(stack, att2, 0, n-2))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
