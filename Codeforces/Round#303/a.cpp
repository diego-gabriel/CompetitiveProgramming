#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector <int> res;
	int d;
	for (int i =0; i < n ;i++){
		bool good = true;
		for (int j = 0; j <n ; j++){
			cin>>d;

			if (d == 1 || d == 3)
				good = false;
		}

		if (good)
			res.push_back(i+1);
	}
	cout<<res.size()<<endl;
	for (int i = 0; i < res.size(); i++){
		if (i > 0)
			cout<<" ";
		cout<<res[i];
	}
	cout<<endl;
	return 0;
}
