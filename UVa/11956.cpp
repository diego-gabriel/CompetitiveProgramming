#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int n;
	cin>>n;
	string prog;
	for (int test = 1; test <= n; test++){
		cin>>prog;

		unsigned char memo[100], ins;
		int i = 0;
		memset(memo, 0, sizeof(memo));

		for (int j = 0; j < prog.size(); j++){
			ins = prog[j];

			if (ins == '<')
				i = (i+99) % 100;
			if (ins == '>')
				i = (i+1) % 100;
			if (ins == '+')
				memo[i]++;
			if (ins == '-')
				memo[i]--;
		}
		printf("Case %d:", test);
		for (int j = 0; j < 100; j++){
			printf(" %02X", memo[j]);
		}
		printf("\n");
	}
	return 0;
}