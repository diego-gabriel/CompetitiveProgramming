#include <iostream>
#include <map>

using namespace std;

int ancestor(int n){
	return n/2;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int i, j, k;
		cin>>i>>j;
		map <int, bool> marked;
		k = i;
		int li, lj, la;
		li = lj = la = 0;
		do{
			li++;
			marked[k] = true;
			k = ancestor(k);
		} while (k);
		
		k = j;

		do{
			lj++;
			if (la == 0 && marked[k])
				la = k;
			if (la == 0)
				marked[k] = true;
			k = ancestor(k);
		} while (k);

		k = la;
		la = 0;
		do{
			la++;
			k = ancestor(k);
		} while (k);

		cout<<lj+li-2*la<<endl;

	}
	return 0;
}