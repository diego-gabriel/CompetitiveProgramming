#include <iostream>

using namespace std;

int main(){
	int n, k;

	cin>>n>>k;
	int score;
	int res = 0;
	bool ok = true;
	int v;
	for (int i = 0; i < n; i++){
		cin>>v;
		ok = ok && v > 0;
		if (ok){
			if (k){
				res++;
				k--;
				score = v;
			}
			else{
				ok = v == score;
				if (ok)
					res++;
			}
		}
	}
	cout<<res<<endl;

	return 0;
}