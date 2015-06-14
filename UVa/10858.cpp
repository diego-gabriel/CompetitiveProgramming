#include <iostream>
#include <vector>

using namespace std;


vector <vector<int> > res;
vector <int> fact;

void solve(int n, int d){
	for (int i = d; i * i <= n; i++){
		if (n % i == 0){
			fact.push_back(i);
			solve(n/i, i);
			fact.pop_back();
		}
	}
	fact.push_back(n);
	res.push_back(fact);
	fact.pop_back();
}


int main(){

	int n;
	while (cin>>n && n){
		res.clear();
		fact.clear();
		solve(n, 2);

		cout<<res.size()-1<<endl;
		for (int i = 0; i < res.size()-1; i++){
			cout<<res[i][0];
			for (int j = 1; j < res[i].size(); j++){
				cout<<" "<<res[i][j];
			}
			cout<<endl;
		}
	}

	return 0;
}