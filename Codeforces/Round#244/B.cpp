#include <iostream>

using namespace std;

int main(){
	int n, t, c;
	cin>>n>>t>>c;
	int menores = 0;
	int ways = 0;
	int level;
	while (n--){
		cin>>level;
		if (level > t){
			ways += max(0, menores - c + 1);
			menores = 0;
		}
		else
			menores++;
	}
	ways += max(0, menores - c + 1);
	cout<<ways<<endl;
	return 0;
}