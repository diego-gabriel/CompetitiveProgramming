#include <iostream>
#include <cstring>

using namespace std;

int max(int a, int b){
	return a < b ? b : a;
}

int main(){
	int nTest;
	cin>>nTest;

	while (nTest--){
		int totalCost;
		int n;
		cin>>totalCost>>n;
		int cost;
		string state;
		while (n--){
			cin>>cost>>state;
			if (state[0] == 'u')
				totalCost -= cost;
		}

		cout<<max(-1, totalCost)<<endl;
	}
	return 0;
}