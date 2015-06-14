#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long req[5];

int main(){
	long long nTest;
	cin>>nTest;

	req[0] = 1;
	req[1] = 2;
	req[2] = 4;
	req[3] = 8;
	req[4] = 16;

	for (long long test = 1; test <= nTest; test++){
		long long c, d, v;
		cin>>c>>d>>v;
		long long den[d];
		for (long long i = 0; i < d; i++){
			cin>>den[i];
		}
		
		long long maxReach = 0;
		long long res = 0;

		for (long long i = 0; i < d  || maxReach < v; i++){
			if (i < d){
				long long coin = den[i];
				//cout<<"maxREach = "<<maxReach<<endl;
				//cout<<"curr coin: "<<coin<<endl;
				if (coin <= maxReach+1){
				//	cout<<"ok"<<endl;
					maxReach += coin*c;
				}	
				else{
				//	cout<<"newCoin: "<<maxReach+1<<endl;
					res++;
					long long mr = maxReach;
					maxReach += (mr+1)*c;
					i--;
				}
			}
			else{
				//cout<<"newCoin: "<<maxReach+1<<endl;
				res++;
				long long mr = maxReach;
				maxReach += (mr+1)*c;
				i--;
			}

		}

		cout<<"Case #"<<test<<": "<<res<<endl;
	}
	return 0;
}