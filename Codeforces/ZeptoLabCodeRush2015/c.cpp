#include <iostream>

using namespace std;

long long c, hr, hb, wr, wb;

long long happy(long long cr){

	long long wfr = cr * wr;
	long long rw = c - wfr;
	long long cb = rw / wb;

	return cr * hr  + cb * hb;
}

bool check (long long happiness){
	bool res = happy(0) >= happiness || happy(c/wr) >= happiness;
	long long ini, fin, mid;
	ini = 0; 
	fin = c / wr;

	while (fin - ini > 1 && !res){
		//if (happiness == 16)
		//cout<<"-----||||  "<<ini<<" - "<<fin<<endl;
		mid = (ini + fin) / 2;
		if (happy(mid) >= happiness)
			res = true;
		else
			fin = mid;
	}
	
	ini = 0; 
	fin = c / wr;

	while (fin - ini > 1 && !res){
		//if (happiness == 16)
	//	cout<<"-----||||  "<<ini<<" - "<<fin<<endl;
		mid = (ini + fin) / 2;
		if (happy(mid) >= happiness)
			res = true;
		else
			ini = mid;
	}

	return res;
}

int main(){
	cin>>c>>hr>>hb>>wr>>wb;

	long long res = 0;

	long long ini; 
	long long fin;
	long long mid;
	ini = 0;
	fin = 0x0fffffffffffffff;

	while (fin - ini > 1){
	//	cout<<ini<<" - "<<fin<<endl;
		mid = (ini + fin) / 2;

		if (check(mid)){
			ini = mid;
		}
		else
			fin = mid;
	}

	cout<<ini<<endl;

	return 0;
}