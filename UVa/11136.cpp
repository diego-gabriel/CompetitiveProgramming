#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main(){

	long long n;

	while (scanf("%lld", &n) && n){
		multiset<long long> urn;
		multiset<long long> :: iterator b, e;

		long long k;
		long long v;
		long long i, j;
		long long res = 0;
		for (i = 0; i < n; i++){
			scanf("%lld", &k);
			for(j = 0; j < k; j++){
				scanf("%lld", &v);
			//	cout<<"read: "<<v<<" size: "<<urn.size()<<endl;
				urn.insert(v);
			//	cout<<"now: "<<urn.size()<<endl;
			}
			b = urn.begin();
			e = urn.end();
			e--;

			//cout<<"min: "<<(*b)<<" max: "<<(*e)<<endl;
			res += ((*e) - (*b));
			urn.erase(b);
			urn.erase(e);
		}

		printf("%lld\n", res);
	}

	return 0;
}