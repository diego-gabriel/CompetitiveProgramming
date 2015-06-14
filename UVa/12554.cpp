#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string song[16];
	song[0] = "Happy";
	song[1] = "birthday";
	song[2] = "to";
	song[3] = "you";
	song[4] = "Happy";
	song[5] = "birthday";
	song[6] = "to";
	song[7] = "you";
	song[8] = "Happy";
	song[9] = "birthday";
	song[10] = "to";
	song[11] = "Rujia";
	song[12] = "Happy";
	song[13] = "birthday";
	song[14] = "to";
	song[15] = "you";

	int n;
	cin>>n;
	string name[n];

	for (int i = 0; i < n; i++)
		cin>>name[i];

	for (int k = 0; k < (n+15)/16; k++){
		for (int i = 0; i < 16; i++){
			cout<<name[(k*16 + i)%n]<<": "<<song[i]<<endl;
		}
	}
	return 0;
}