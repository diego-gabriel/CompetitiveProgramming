#include <iostream>
#include <cstdio>

using namespace std;

int even, odd;
int nTest, n, k, i, nA, test;

int main(){
	scanf("%d", &nTest);
	for (test = 1; test <= nTest; test++){
		scanf("%d %d", &n, &k);
		odd = even = 0;

		for (i = 1; i <= n; i++){
			nA = min(n-i, k);
			if (i <= k)
				nA += (n-i);
			if (nA % 2 == 0)
				even++;
			else
				odd++;
		}

		printf("Case #%d:\n", test);
		if (odd % 2 == 1)
			cout<<"odd ";
		else
			cout<<"even ";
		if (even % 2 == 1)
			cout<<"odd"<<endl;
		else
			cout<<"even"<<endl;
	}

	return 0;
}

