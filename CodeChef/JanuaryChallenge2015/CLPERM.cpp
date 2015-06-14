#include <iostream>
#include <set>

using namespace std;

long long sum (long long n){
	return (n * (n+1))/ 2;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		long long n, k;
		cin>>n>>k;
		set<long long> s;
		set<long long> :: iterator it;
		long long a;
		for (int i = 0; i < k; i++){
			cin>>a;
			s.insert(a);
		}

		it = s.begin();
		long long last = 0;
		long long tot = 0;
		while (it != s.end()){
			if (tot - last < -1)
				break;
			tot += sum(*it -1) - sum(last-1);
			last = *it +1;

			while (it != s.end()){
				it++;
				if (*it != last) break;
				last = *it +1;

			}

		}
		if (tot - last >= -1)
			tot += sum(n) - sum(last-1);
		if (tot%2 == 1)
			cout<<"Mom"<<endl;
		else
			cout<<"Chef"<<endl;
	}
	return 0;
}