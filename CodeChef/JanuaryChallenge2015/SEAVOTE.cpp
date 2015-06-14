#include <iostream>
#include <set>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		multiset<int> valid;
		int total = 0;
		for (int i = 0; i < n; i++){
			int b;
			cin>>b;
			total+= b;
			if (b)
				valid.insert(b);
		}

		if (total >= 100 && total - 100 <= valid.size()-1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}