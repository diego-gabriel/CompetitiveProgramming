#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Animal
{
	int number, legs;

	Animal(){};
	Animal(int a, int b){
		legs = a;
		number = b;
	}
};

bool operator < (Animal a, Animal b){
	return a.legs < b.legs;
}

int main(){
	int nt;
	cin>>t;
	int nTest = 0;
	while (t--){
		nTest++;
		int n, k;
		cin>>n>>k;

		vector <Animal> res;
		int legs;
		vector <int>l;
		int lastDiff = 0x7fffffff;
		int lastLegs = 0;
		cin>>lastLegs;
		bool ok = true;
		int posN = 0;
		for (int i = 1; i < k+1 ; i++){
			cin>>legs;
			l.push_back(legs);

			int dif = lastLegs - legs;
			if (dif > lastDiff)
				ok = false;
			if (lastDiff > dif)
				posN++;

			lastDiff = dif;
			lastLegs = legs;
		}
		if (lastDiff > lastLegs)
			posN++;
		ok = ok && posN == n;
		cout<<"Case #"<<nTest<<":"<<endl;
		if (ok){


		}
		else{
			cout<<"No Solution"<<endl;
		}

	}
	return 0;
}