#include <iostream>
#include <cstdio>

using namespace std;



int main(){
	int test;
	cin>>test;

	for (int nTest = 1; nTest <= test; nTest++){
		double c, f, x;
		cin>>c>>f>>x;
		double tToBuy, relTime, tRest, tCom, r;
		r = 2.0;
		relTime = 0.0;
		tToBuy = c / r;
		tRest = x / r;
		tCom = relTime + tToBuy + (x /(r + f));
		while (tRest > tCom){
			//cout<<tCom<<" - "<<tRest<<endl;
			relTime += tToBuy;
			r += f;
			tRest = relTime + (x/r);
			tToBuy = c/r;
			tCom = relTime + tToBuy + (x /(r + f));
		}

		cout<<"Case #"<<nTest<<": ";
		printf("%.7f\n", tRest);
	}
}