#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool solved[505][505][505];
int memo[505][505][505];
int bugs[505];
int n, m, bug, mod;

int solve(int p, int l, int b){
	if (!solved[p][l][b]){
		solved[p][l][b] = true;
		int res = 0;
		if (b <= bug){
			if (p == n){
				int totBugs = b + l*bugs[p];
				//cout<<"totBugs: "<<totBugs<<endl;
				if (totBugs <= bug)
					res = 1;
			}
			else{
				for (int i = 0; i <= l; i++){
					res += solve(p+1, l-i, b+bugs[p]*i);
					res %= mod;
				}
			}
		}
		memo[p][l][b] = res;
	}

	return memo[p][l][b];
}


int main(){
	cin>>n>>m>>bug>>mod;
	memset(memo, 0, sizeof(memo));
//	memset(bugs, 0, sizeof(bugs));
	memset(solved, false, sizeof(solved));

	for (int i = 1; i <= n; i++)
		cin>>bugs[i];

	cout<<solve(1, m, 0)<<endl;
	return 0;
}