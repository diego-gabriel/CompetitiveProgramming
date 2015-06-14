#include <iostream>
#include <set>

using namespace std;

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int nTest;
	cin>>nTest;

	while (nTest--){
		int n;
		cin>>n;
		set<int> s;
		int f[n];
		int v, res;
		res = 0;
		int last = 0;
		for (int i = 0; i < n; i++){
			cin>>v;
			f[i] = v;
			if (s.find(v) != s.end()){
				//cout<<"rep: "<<v<<endl;
				while (f[last] != v){
					s.erase(f[last]);
				//	cout<<"erased: "<<f[last]<<endl;
					last++;
				}
				last++;
			}
			else
				s.insert(v);

			res = max(res, s.size());
		}

		cout<<res<<endl;
	}
	return 0;
}