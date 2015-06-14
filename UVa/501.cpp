#include <iostream>
#include <set>
#include <cstdio>
using namespace std;


int main(){
	multiset<int> aSet;
	multiset<int> :: iterator it;

	
	int t;
	scanf("%d", &t);
	while (t--){
		aSet.clear();
		int m, n;
		scanf("%d %d", &m, &n);
		int a[m];
		int u[n];
		for (int i = 0; i < m; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++){
			scanf("%d", &u[i]);
		}
		int in = 0;
		int k = 0;
		it = aSet.begin();

		for(int i = 0; i < n; i++){


			while (in < u[i]){
				aSet.insert(a[in]);

				if (*it > a[in]){
					it--;
				}

				in++;
			}

			if (i == 0){
				it = aSet.begin();
			}
			else
				it++;

			cout<<*it<<endl;
		}


		if (t) cout<<endl;
	}
	return 0;
}