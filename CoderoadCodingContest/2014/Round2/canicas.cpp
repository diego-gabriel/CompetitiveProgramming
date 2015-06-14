#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m;
int c[11];
char memo[100000+5][2];

bool solve(int n, bool pl){
	int cal = memo[n][pl];
	bool res;
	if (cal != 0)
		res = cal == 2;
	else{
		if (n == 0){
			memo[n][pl] = 2;
			res = true;
		}
		else{
			bool canWin = false;
			for (int i = 0; i < m; i++){
				if (n-c[i] >= 0)
					canWin = canWin || !solve(n-c[i], !pl);
			}
			memo[n][pl] = canWin+1;
			res = canWin;
		}
	}
	return res;
}

int main(){
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		cout<<"Caso #"<<test<<": ";
		cin>>n>>m;
		for (int i = 0; i < m; i++)
			cin>>c[i];
		sort(c, c+m);
		memset(memo, 0, sizeof(memo));
		if (solve(n, 1)) cout<<"SI"<<endl;
		else
		cout<<"NO"<<endl;

	}
	return 0;
}