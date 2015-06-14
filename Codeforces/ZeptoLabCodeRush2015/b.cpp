#include <iostream>
#include <vector>

using namespace std;

long long r;
vector <int> a;
int n;

bool isLeaf(int node){
	return (node >= (1 << n) && node <= (1<<(n+1))-1);
}

int solve(int node){

	int res = 0;

	if (isLeaf(node)){
		res = a[node];
	}
	else
	{
		int der = solve(node*2+1);
		int izq = solve(node*2);

		int m = der > izq ? der : izq;
		int l = der < izq ? der : izq;
		r += (m-l);

		res = m + a[node];
	}

	return res;
}

int main(){
	cin>>n;
	r = 0;
	a.assign((1<<(n+1) )+ 5, 0);
	for (int i = 2; i <= (1<<(n+1))-1; i++){
		cin>>a[i];
	}

	solve(1);
	cout<<r<<endl;
	return 0;
}