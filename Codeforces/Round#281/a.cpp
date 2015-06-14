#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string th, ta;
	cin>>th>>ta;
	int n;
	cin>>n;

	int fh[101], fa[101];
	memset(fh, 0, sizeof(fh));
	memset(fa, 0, sizeof(fa));
	int t;
	char l;
	int m;
	char c;
	for (int i = 0; i < n; i++){
		cin>>t>>l>>m>>c;
		if (l == 'h'){
			if (c == 'y'){
				if (fh[m] == 0)
					fh[m] = 1;
				else
				if (fh[m] == 1){
					fh[m] = 2;
					cout<<th<<" "<<m<<" "<<t<<endl;
				}
			}
			else
			if (fh[m] != 2){
				fh[m] = 2;
				cout<<th<<" "<<m<<" "<<t<<endl;	
			}

		}
		else {
			if (c == 'y'){
				if (fa[m] == 0)
					fa[m] = 1;
				else
				if (fa[m] == 1){
					fa[m] = 2;
					cout<<ta<<" "<<m<<" "<<t<<endl;
				}
			}
			else
			if (fa[m] != 2){
				fa[m] = 2;
				cout<<ta<<" "<<m<<" "<<t<<endl;	
			}
		}
	}

	return 0;
}