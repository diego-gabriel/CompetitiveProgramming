#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	//cout<<(4*5000000 / 1000000)<<endl;
	vector<int> memo(5000000+1);
	for (int i = 0; i <= 5000000; i++)
		memo[i] = 0;
	//cout<<"lala"<<endl;
	//cout<<"ups"<<endl;
	for(int i = 2; i < 3000; i++){
		if (memo[i] == 0)
		for (int k = i; k <= 5000000; k += i){
			memo[k] = i;
		}
	}

	//cout<<"done"<<endl;

	for (int i = 2; i <= 5000000; i++){
		if (memo[i] == 0)
			memo[i] = i;

		memo[i] = memo[i/memo[i]]+1;
	}

	for (int i = 1; i <= 5000000; i++){
		memo[i]+= memo[i-1];
	}

	int n;
	cin>>n;

	while (n--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", memo[a]-memo[b]);
	}
	return 0;
}