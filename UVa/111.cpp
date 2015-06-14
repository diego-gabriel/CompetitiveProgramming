#include <iostream>
#include <map>

using namespace std;

int main(){
	int n;
	cin>>n; 

	map <int, int> order;
	int r;
	for (int i = 0; i < n; i++){
		cin>>r;
		r--;
		order[i] = r;
		//cout<<r<<" -> "<<i<<endl;
	}
	int stud[n];
	while(cin>>r){
		r--;
		//cout<<r<<"*->"<<order[r]<<endl;
		stud[r] = order[0];
		for (int i = 1; i < n; i++){
			cin>>r;
			r--;
			stud[r] = order[i];
		}

		int lis[n];

		for (int i = 0; i < n; i++)
			lis[i] = 1;

		for (int i = n-1; i >= 0; i--){
		//	cout<<stud[i]<<" ";
			for (int j = i+1; j < n; j++){
				if (stud[i] < stud[j])
					lis[i] = max(lis[i], lis[j] +1);
			}
		}
		//cout<<endl;

		int res = 0;

		for (int i = 0; i < n; i++)
			res = max(res, lis[i]);

		cout<<res<<endl;
	}

	return 0;
}