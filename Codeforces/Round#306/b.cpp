#include <iostream>
#include <map>

using namespace std;

map <int, int> nBit;

int main(){
	int n, l, r, x;
	cin>>n>>l>>r>>x;
	int c[n];
	int nb = 1;
	for(int i = 0; i < n; i++){
		cin>>c[i];
		nBit[nb] = i;
		nb = nb << 1;
	}
//	cout<<"read"<<endl;
	int bMask;
	int sum;
	int min;
	int max;
	int cant;
	int i,item;
	int res = 0;
	for (int mask = 0; mask < (1<<n); mask++){
	//	cout<<"mas: "<<mask<<endl;
		bMask = mask;
		sum = 0;
		min = 1000000+10;
		max = 0;
		cant = 0;

		while (bMask){
	//		cout<<bMask<<endl;
			i = bMask & (-bMask);
			bMask = bMask-i;
			item = c[nBit[i]];

			min = min < item ? min : item;
			max = max > item ? max : item;
			sum += item;
			cant++;

		}

		if (cant >= 2 && sum >= l && sum <= r && (max-min) >= x)
			res++;
	}

	cout<<res<<endl;

	return 0;
}