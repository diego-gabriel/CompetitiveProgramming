#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool rev(int a, int b){
	return a > b;
}

int main(){

	vector <int> numbers[3];
	vector <bool> used[3];
	int n;
	cin>>n;
	int v;
	bool flag = false;
	int sum = 0;
	for (int i = 0; i < n; i++){
		cin>>v;
		numbers[v%3].push_back(v);
		used[v%3].push_back(true);
		if (!flag && v == 0)
			flag = true;
		sum += v;
	}

	if (!flag)
		cout<<"-1"<<endl;
	else{
		flag = false;
		int lastIt[3];
		for (int i = 0; i < 3; i++){
			sort(numbers[i].begin(), numbers[i].end(), rev);
			lastIt[i] = ((int)numbers[i].size())-1;
		}

		int diff = sum % 3;
		flag = diff == 0;
		if (diff == 1){
			int it = lastIt[diff];
			if (it >= 0){
				used[diff][it] = false;
				sum -= numbers[diff][it];
				lastIt[diff]--;
				flag = true;
			}
			else{
				it = lastIt[2];
				if (it >= 1){
					sum -= numbers[2][it];
					sum -= numbers[2][it-1];
					used[2][it] = false;
					used[2][it-1] = false;
					lastIt[2]--;
					lastIt[2]--;
					flag = true;
				}
			}

		}
		if (diff == 2){

			int it = lastIt[diff];
			//cout<<"enter diff "<<diff<<" " <<it<<endl;
			if (it >= 0){
				used[diff][it] = false;
				sum -= numbers[diff][it];
				lastIt[diff]--;
				flag = true;
			}
			else{
			//	cout<<"enter2"<<endl;
				it = lastIt[1];
				if (it >= 1){
					sum -= numbers[1][it];
					sum -= numbers[1][it-1];
					used[1][it] = false;
					used[1][it-1] = false;
					lastIt[1]--;
					lastIt[1]--;
					flag = true;
				}
			}
			//cout<<"exit"<<endl;
		}

		if (flag){
			vector<int> all;
			for (int i  = 0; i < 3; i++){
				for (int j = 0; j < numbers[i].size(); j++){
					if (used[i][j])
						all.push_back(numbers[i][j]);
				}
			}

			if (sum == 0)
				cout<<0<<endl;
			else
			{
				sort(all.begin(), all.end(), rev);
				for (int i  = 0;i < all.size(); i++){
					cout<<all[i];
				}
				cout<<endl;
			}
		}
		else
			cout<<"-1"<<endl;
	}

	return 0;
}