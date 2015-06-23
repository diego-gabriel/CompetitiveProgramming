#include <iostream>
#include <vector>

using namespace std;

int main(){
	int x, y, a, b;
	cin>>x>>y>>a>>b;
	if (a <= b)
		a = b+1;
	int n = (x-a+1)*(y-b+1);
	vector<pair<int, int> > res;
	int k = b;
	while (a <= x){
		b = k;
		while (b <= y && b < a){
			res.push_back(make_pair(a, b));
			b++;
		}
		a++;
	}

	cout<<res.size()<<endl;

	for(int i = 0; i < res.size(); i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
	return 0;
}