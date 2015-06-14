#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Ins
{
	int id;
	int days;
	Ins(){};
};


bool ord(Ins a, Ins b){
	return a.days < b.days;
}

int main(){
	int n, k;
	cin>>n>>k;
	Ins a[n+1];
	for (int i = 0; i < n; i++){
		cin>>a[i].days;
		a[i].id = i+1;
	}
	a[n].days = k+1;
	a[n].id = n+1;
	sort(a, a+(n+1), ord);

	int s = 0;
	vector <int> res;
	int i = 0;
	while (k >= 0){
		k -= a[i].days;
		res.push_back(a[i].id);
		i++;
	}

	cout<<res.size()-1<<endl;
	if (res.size()-1 > 0){
		cout<<res[0];
		for (int k = 1; k < res.size()-1; k++)
			cout<<" "<<res[k];
		cout<<endl;
	}

	return 0;
}