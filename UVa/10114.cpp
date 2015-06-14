#include <iostream>

using namespace std;

int main(){
	int mToPay;
	double pay, amount, value;
	int nDep;
	while(cin>>mToPay>>pay>>amount>>nDep && mToPay >= 0){
		int res = 0;
		value = amount + pay;
		pay = amount / ((double)mToPay);
		int m, nM;
		double d, nD;
		double dep[mToPay+5];
		while (nDep--){
			cin>>m>>d;
			for (int i = m; i < mToPay+4; i++){
				dep[i] = d;
			}
		}
		value -= (value*dep[0]);
		while (value < amount){
			res++;
			value -= (value*dep[res]);
			amount -= pay;
		}

		cout<<res<<" month"<<(res != 1 ? "s" : "")<<endl;
	}


	return 0;
}