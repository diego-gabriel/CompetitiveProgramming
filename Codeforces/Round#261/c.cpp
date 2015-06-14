#include <iostream>

using namespace std;

int mat[1003][1003];
int n, k, d;
int min(int a, int b){
	return a < b ? a : b;
}

bool acom(int ini, int fin, int bus, int dia){
	bool res = dia <= d;

	//cout<<"ender: "<<ini<<" - "<<fin<<"		on bus: "<<bus<<" | dia:"<<dia<<endl;
	if (res){
		for (int i = ini; i <= fin; i++){
			mat[dia][i] = bus;
		}
		int totPax = fin-ini +1;
		int nBus = min(k, totPax);
		if (totPax == 1){
			for (int day = dia; day <= d; day++){
				mat[day][ini] = bus;
			}
		}
		else{
			int nPax = (totPax+k-1)/k;
			for (int b = 1; b <= k && res; b++){
				res = acom(ini+nPax*(b-1), ini+min(nPax*b, n)-1, b, dia+1);
			}
		}
	}
	return res;
}

int main(){
	cin>>n>>k>>d;

		k = min(n, k);
		int npax = (n+k-1) / k;
		bool ok = true;
		for (int bus = 1; bus <= k && ok; bus++){
			ok = acom(npax*(bus-1)+1, min(npax*bus, n), bus, 1);
		}

		if (ok){
			for (int day = 1; day <= d; day++){
				cout<<mat[day][1];
				for (int i = 2; i <= n; i++){
					cout<<" "<<mat[day][i];
				}
				cout<<endl;
			}
		}
		else cout<<-1<<endl;
	
	return 0;
}