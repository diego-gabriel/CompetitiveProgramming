#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	bool fst = true;
	while (t--){
		if (!fst)
			cout<<endl;
		int w;
		cin>>w;
		bool res = true;
		bool first = true;
		int x, y;
		int gap;
		for (int i = 0; i < w; i++){
			cin>>x>>y;

			if (first){
				gap = (y-x);
				first = false;
			} else {
				res = res && (y - x) == gap;
			}
		}


		if (res) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		fst = false;
	}
	return 0;
}