#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int n, t;
	while (cin>>n){
		cin>>t;

		int maxUsage = 0;
		int s[t];
		for (int i = 0; i < t; i++)
			cin>>s[i];


		int bestMask;
		for (int mask = 1; mask < (1<<t); mask++){
			int sum = 0;
			for (int bit = 0; bit < t; bit++){
				if (mask & (1<<bit)){
					sum += s[bit];
				}
			}

			if (sum <= n && sum >= maxUsage){
				bestMask = mask;
				maxUsage = sum;
			}
		}


		vector <int> res;
		//cout<<"bestmask: "<<bestMask<<" sum: "<<maxUsage<<endl;
		for (int bit = 0; bit < t; bit++){
			if (bestMask & (1<<bit))
				res.push_back(s[bit]);
		}

		cout<<res[0];
		for (int i = 1; i < res.size(); i++)
			cout<<" "<<res[i];
		cout<<endl;
	}
	return 0;
}