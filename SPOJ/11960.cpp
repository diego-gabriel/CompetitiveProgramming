#include <iostream>
#include <cstring>

using namespace std;

bool primo[1000000+1];

void initCriba(){
	memset(primo, true, sizeof(primo));

	primo[0] = primo[1] = false;

	for (int i = 2; i <= 1000; i++){
		if (primo[i])
			for (int j = 2*i; j <= 1000000; j += i){
				primo[j] = false;			
			}
	}
}

int main(){
	long long n;
	initCriba();
	
	while (cin>>n){
		long long factor = 2;
		if (n < 2){
			cout<<n<<endl;
			continue;
		}
		factor = 1;
		while (n != 1){
			do{
				factor++;
			}while (!primo[factor] && factor < 1000000);

			if (factor == 1000000){
				cout<<n<<endl;
				break;
			}

			if (n % factor == 0){
				while (n % factor == 0)
					n /= factor;
				cout<<factor<<endl;
			}

		}
	}

	return 0;
}