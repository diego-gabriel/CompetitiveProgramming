#include <iostream>
#include <cstring>

using namespace std;

bool check (string cad, int begin, int step){
	int c = 0;
	bool res = false;
    for (int i = begin; i < cad.size() && !res; i += step){
		
		if (cad[i] == '*')
			c++;
		else
			c = 0;
		//cout<<c<<endl;
		if (c == 5)
			res = true;
	//	cout<<res<<"---"<<endl;
	}

	//cout<<"start: "<<begin<<" step "<<step<<" res "<<res<<endl;


	return res;
}

int main(){
	int n;
	string cad;
	cin>>n;
	cin>>cad;

	bool flag = false;
	for (int i = 1; i <= 20 && !flag; i++){
		for (int j = 0; j < i && !flag; j++)
			flag = check(cad, j, i);
	}

	if (flag)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}