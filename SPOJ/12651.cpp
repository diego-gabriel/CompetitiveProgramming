#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main(){
	int n;
	while (cin>>n){
		vector <int> pos, sum;

		int s = 0;
		int v;
		int total = 0;
		for (int i = 0; i < n; i++){
			cin>>v;
			pos.push_back(v);
			total += v;
		}

		sum.push_back(0);

		for (int i = 0; i < n; i++){
			s += pos[i];
			sum.push_back(s);
		}
		for (int i = 0; i < n; i++){
			s += pos[i];
			sum.push_back(s);
		}
		set <int> ok;

		for (int i = 0; i < sum.size(); i++){
			ok.insert(sum[i]);
		}

		int target = total / 3;
		int res = 0;
		if (target*3 == total){
			for (int i = 0; i < n; i++){
				if (ok.find(sum[i]) != ok.end()
				 && ok.find(sum[i]+target) != ok.end()
				 && ok.find(sum[i]+2*target) != ok.end())
					res++;
			}

		}

		cout<<res<<endl;

	}
	return 0;
}