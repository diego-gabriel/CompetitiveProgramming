#include <iostream>

using namespace std;

int main(){
	int n, max, a, cur;

	cin>>n;
	max = 0;
	cur = 0;
	while (n--){
		cin>>a;
		cur = (a == 0 ? 0 : cur+1);
		max = (cur > max ? cur : max);
	}

	cout<<max<<endl;
	return 0;
}