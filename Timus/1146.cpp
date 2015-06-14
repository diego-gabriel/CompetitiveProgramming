#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);

	int mat[n][n];
	bool allNeg = true;
	int maxNum = -128;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &mat[i][j]);
			allNeg = allNeg && mat[i][j] < 0;
			//cout<<"read "<<mat[i][j]<<endl;
			maxNum = maxNum > mat[i][j] ? maxNum : mat[i][j];
			//cout<<"max: "<<maxNum<<endl;
		}
	}

	int sum[n];
	int res = 0;
	int best = 0;
	int cur = 0;

	if (allNeg){
		res = maxNum;
		//cout<<"allNeg "<<maxNum<<" "<<res<<endl;
	}
	else
		for (int k = 0; k < n; k++){
			memset(sum, 0, sizeof(sum));
		
			for (int i = k; i < n; i++){
				for (int j = 0; j < n; j++){
					sum[j] += mat[i][j];
					////cout<<" "<<sum[j];
				}
				////cout<<endl;

				cur = 0;
				best = 0;
				////cout<<"k: "<<k<<" i: "<<i<<endl;
				for (int j = 0; j < n; j++){
					cur += sum[j];
					////cout<<"cur: "<<cur<<endl;
					if (cur < 0)
						cur = 0;

					best = best > cur ? best : cur;
				}
				res = res > best ? res : best;
			}
		}

	printf("%d\n", res);

	return 0;
}