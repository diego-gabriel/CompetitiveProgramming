#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int main(){
	int n;
	cin>>n;
	map <queue<int>, map <queue<int> , bool> > memo;
	queue<int> one, two;

	int k, v;
	cin>>k;
	for (int i = 0; i < k; i++){
		cin>>v;
		one.push(v);
	}
	cin>>k;
	for (int i = 0; i < k; i++){
		cin>>v;
		two.push(v);
	}

	int res = 0;
	while (!one.empty() && !two.empty() && !memo[one][two]){
		memo[one][two] = true;
		res++;
		int c1, c2;
		c1 = one.front();
		one.pop();
		c2 = two.front();
		two.pop();

		if (c1 > c2){
			one.push(c2);
			one.push(c1);
		}
		else
		{
			two.push(c1);
			two.push(c2);
		}
	}

	if (one.empty()){
		cout<<res<<" 2"<<endl;
	}
	else if(two.empty()){
		cout<<res<<" 1"<<endl;
	}
	else
		cout<<-1<<endl;
	return 0;
}