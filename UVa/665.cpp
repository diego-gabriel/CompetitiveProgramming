#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool notIn(int n, vector <int> v){
	bool res = true;

	for (int i = 0; i < v.size() && res; i++){
		res = v[i] != n;
	}

	return res;
}

int countTrue(vector <bool> v){
	int res = 0;

	for (int i = 0; i < v.size(); i++)
		if (v[i])
			res++;

	return res;
}

int getTrue(vector <bool> v){
	int res;

	for (int i = 0; i < v.size(); i++){
		if (v[i])
			res = i;
	}

	return res;
}

int main(){
	int t;
	cin>>t;

	while (t--){
		int n, k;
		cin>>n>>k;

		vector <bool> isFalse(n, true);
		int p;
		
		vector <int> coins;
		for (int i = 0; i < k; i++){
			coins.clear();
			cin>>p;
			int v;
			for (int j = 0; j < p*2; j++){
				cin>>v;
				coins.push_back(v-1);
			}

			char s;
			cin>>s;
			if (s == '=')
				for (int j = 0; j < 2*p; j++){
					isFalse[coins[j]] = false;
				}
			else {
				for (int j = 0; j < n; j++){
					if (notIn(j, coins))
						isFalse[j] = false;
				}
			}

		}

		if (countTrue(isFalse) == 1)
			cout<<getTrue(isFalse)+1<<endl;
		else
			cout<<0<<endl;
		if (t)
		cout<<endl;
	}	
	return 0;
}