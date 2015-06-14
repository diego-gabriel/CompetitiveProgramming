#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool match(int a, int b){
//	cout<<"matching "<<a<<" "<<b<<endl;
	if (a < b)
		swap(a, b);
	return (a -b) <= 1;
}	

int main(){
	int n, m, v;
	cin>>n;
	vector <int> a, b;
	for(int i = 0; i < n; i++){
		cin>>v;
		a.push_back(v);
	}
	cin>>m;
	for (int i = 0; i < m; i++){
		cin>>v;
		b.push_back(v);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int j = -1;
	int res = 0;
/*
	cout<<"a: "<<endl;
	for(int i = 0; i < n; i++){
		cout<<" "<<a[i];
	}
	cout<<endl;
	cout<<"b: "<<endl;
	for(int i = 0; i < m; i++){
		cout<<" "<<b[i];
	}
	cout<<endl;
*/
	for (int i = 0; i < n; i++){
		for (int k = j+1; k < m; k++){
			if (match(a[i], b[k])){
			//	cout<<"matched "<<a[i]<<" -- "<<b[k]<<endl;
				res++;
				j = k;
				break;
			}
		}
	}
	cout<<res<<endl;

	return 0;
}