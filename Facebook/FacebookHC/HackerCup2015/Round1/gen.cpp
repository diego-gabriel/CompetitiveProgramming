#include <iostream>
#include <cstring>

using namespace std;

int main(){

	cout<<1<<endl;
	cout<<10<<endl;
	char k = 'a';
	for (int i = 0; i < 10; i++){
		k = (char)('a' + i);
		for (int j = 0; j < 100000; j++){
			cout<<k;
			if (k == 'z')
				k = 'a';
			else
				k++;
		}
		cout<<endl;
	}
	return 0;
}