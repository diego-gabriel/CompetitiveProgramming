#include <iostream>

using namespace std;

long long best (long long a, long long b){
	return a < b ? b : a;
}
long long worst (long long a, long long b){
	return a < b ? a : b;
}

int main(){
	int n, k;
	cin>>n>>k;
	long long min = 0x00000000ffffffff;
	long long max = -max;
	long long seq[n];
	for (int i = 0; i < n; i++){
		cin>>seq[i];
		max = best(max, seq[i]);
		min = worst(min, seq[i]); 
	}

	if (k) {
		k--;
		for (int i = 0; i < n; i++)
			seq[i] = max - seq[i];
		for (int i = 0; i < n; i++){
			max = best(max, seq[i]);
			min = worst(min, seq[i]);
		}
		k %= 2;
	}

	if (k){

		for (int i = 0; i < n; i++)
			seq[i] = max - seq[i];
		for (int i = 0; i < n; i++){
			max = best(max, seq[i]);
			min = worst(min, seq[i]);
		}
	}

	cout<<seq[0];
	for (int i = 1; i < n; i++)
		cout<<" "<<seq[i];
	cout<<endl;

}