#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	while (cin>>n){
		int v[n];
		for (int i = 0; i < n; i++){
			cin>>v[i];
		}

		int bestIni, bestFin, currIni, currFin;
		int bestSum, currSum;
		bestIni = bestFin = currSum = currFin = currIni = 0;
		bestSum = 0x80000000;

		for (currFin = 0; currFin < n; currFin++){
			currSum += v[currFin];
			if (currSum > bestSum){
				bestSum = currSum;
				bestFin = currFin+1;
				bestIni = currIni;
			}
			if (currSum <= 0){
				currSum = 0;
				currIni = currFin + 1;
			}
		}

		cout<<bestFin-bestIni;
		for (int i =  bestIni; i < bestFin; i++){
			cout<<" "<<v[i];
		}
		cout<<endl;
	}
	return 0;
}