#include <iostream>
#include <cstring>

using namespace std;

short mod(string num, int d){
	short k = 0;

	for (int i = 0; i < num.length(); i++){
		k *= 10;
		k += (num[i]-'0');
		k %= d;
	}

	return k;
}

bool isLeap(string year){
	return (mod(year, 4) == 0 && (mod(year, 100) != 0 || mod(year, 400) == 0));
}

bool huluculu (string year){
	return mod(year, 15) == 0;
}

bool buluculu (string year){
	return mod(year, 55) == 0 && isLeap(year);
}

int main(){
	string year;
	bool fst = true;

	while (cin>>year){
		int c = 0;
		if (!fst)
			cout<<endl;
		if (isLeap(year)){
			c++;
			cout<<"This is leap year."<<endl;
		}
		if (huluculu(year)){
			c++;
			cout<<"This is huluculu festival year."<<endl;
		}
		if (buluculu(year)){
			c++;
			cout<<"This is bulukulu festival year."<<endl;
		}
		if (c == 0)
			cout<<"This is an ordinary year."<<endl;

		fst = false;
	}
	return 0;
}