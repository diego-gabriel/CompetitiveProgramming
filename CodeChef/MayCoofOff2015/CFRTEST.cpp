#include <iostream>
#include <set>

using namespace std;

int main(){
	int n;
	cin>>n;
	while (n--){
		int f;
		cin>>f;
		set<int> res;
		int v;
		while (f--){
			cin>>v;
			res.insert(v);
		}

		cout<<res.size()<<endl;
	}
	return 0;
}