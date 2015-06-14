#include <iostream>
#include <map>
#include <vector>

using namespace std;

int abs(int a){
	return a > 0 ? a : -a;
}

int main(){

	int m, n;

	while (cin>>m>>n){
		map <int, map <int, int> > matrix;
		map <int, int> :: iterator it, jt;
		vector <int> ys;
		for (int x = 1; x <= m; x++){
			int p;
			cin>>p;
			ys.clear();
			for (int i = 0; i < p; i++){
				int v;
				cin>>v;
				ys.push_back(v);
			}
			for (int i = 0; i < p; i++){
				int y = ys[i];
				cin>>matrix[y][x];
			}
		}
		cout<<n<<" "<<m<<endl;
		for (int x = 1; x <= n; x++){
			map <int, int> row = matrix[x];

			cout<<row.size();
			ys.clear();
			for (it = row.begin(); it != row.end(); it++){
				cout<<" "<<it->first;
				ys.push_back(it->second);
			}
			cout<<endl;
			for (int i = 0; i < ys.size(); i++){
				if (i != 0)
					cout<<" ";
				cout<<ys[i];
			}
			cout<<endl;
		}
	}

	return 0;
}