#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){

	int n, m, p;
	map <int, map <int, int> > matrix;
	cin>>n>>m>>p;
	//cout<<n<<" "<<m<<" "<<p<<endl;

	for (int d = 0; d < p; d++)
	{
		int i, j;
		cin>>i>>j;
	//	cout<<"inc: "<<i<<" "<<j<<endl;
		matrix[i][j]++;
	}

	for (int i = 1; i <= n; i++){
	//	cout<<"iterating over: "<<i<<endl;
		vector <int> entries;
		map <int, int> :: iterator it;
		int res = 0;
		for (it = matrix[i].begin(); it != matrix[i].end(); it++){
			entries.push_back(it->first);
	//		cout<<"push: "<<it->first<<endl;
		}
		
		bool possible = true;
		for (int k = 0; k < entries.size() && possible; k++){
			int j = entries[k];
	//		cout<<"=O "<<i<<" "<<j<<endl;
			possible = matrix[i][j] - matrix[i][j+1] <= 1 || j == m;
		} 

		if (possible)
			res = matrix[i][m] - matrix[i][1] + m - 1;
		else
			res = -1;

		cout<<res<<endl;
	}

	return 0;
}