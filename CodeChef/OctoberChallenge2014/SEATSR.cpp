#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 100100

int d[2][MAX];

void init(){
	for (int i = 0; i < MAX; i++){
		d[0][i] = d[1][i] = 200;
	}
}

int min (int a, int b){
	return a < b ? a : b;
}

int max (int a, int b){
	return a > b ? a : b;
}

void print(int n){
	cout<<"----------------------"<<endl;
	for (int i = 0; i < n; i++)
		cout<<" "<<d[0][i];
	cout<<endl;
	for (int i = 0; i < n; i++)
		cout<<" "<<d[1][i];
	cout<<endl;
	cout<<"----------------------"<<endl;
}

int main()
{
	int t;
	cin>>t;
	while (t--){
		string s, w;
		int a, b, k;
		cin>>s>>w>>a>>b>>k;

		if (s.length() < w.length()){
			swap(s, w);
		}

		if (a > 0){
			init();

			int h = s.length();

			for (int i = 0; i < s.length(); i++){
				d[0][i] = i*a;
				if (d[0][i] > k){
					h = i;
					break;
				}
			}
			
			for (int j = 1; j < w.length()+1; j++){
				for (int i = max(0, j-h); i <= min(s.length(), j + h); i++){
					int it, up;
					it = j % 2;
					up = (j-1) % 2;

					if (i == 0){
						d[it][i] = j*a;
					}
					else
					if (i == max(0, j-h)){
						d[it][i] = 200;
					}
					else{

						if (s[i-1] == w[j-1]){
							d[it][i] = d[up][i-1];
						}
						else{
							int ins, del, rep;
							ins = d[it][i-1] + a;
							del = d[up][i] + a;
							rep = d[up][i-1] + b;

							d[it][i] = min(rep, min(ins, del));
						}
					}
				}
			}

			if (d[w.length() % 2][s.length()] > k)
				cout<<-1<<endl;
			else
				cout<<d[w.length() % 2][s.length()]<<endl;

		}
		else 
			cout<<0<<endl;
	}
	return 0;
}