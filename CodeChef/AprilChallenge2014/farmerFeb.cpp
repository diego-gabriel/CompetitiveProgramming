#include <iostream>
#include <cstring>

using namespace std;

bool esPrimo[10000];

void init(){
	memset(esPrimo, true, sizeof(esPrimo));
	esPrimo[0] = esPrimo[1] = false;

	for (int i = 0; i <= 100; i++){
		if (esPrimo[i])
			for (int k = 2*i; k < 10000; k += i)
				esPrimo[k] = false;
	}
}


int main()
{
	int test;
	cin>>test;

	while (test--){
		init();
		int x, y, i;
		cin>>x>>y;

		for (i = x + y + 1; !esPrimo[i]; i++);

		cout<<i - x - y<<endl;
	}
	return 0;
}