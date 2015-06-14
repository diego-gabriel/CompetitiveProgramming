#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

double fact(long long n){
	return n == 0 ? 1.0 : n * fact(n-1);
}

int main(){
	string cad1, cad2;
	cin>>cad1>>cad2;
	double res = 0.0;
	int x, y, a, b, n, i, j;

	x = y = a = b = n = 0;

	for (int c = 0; c < cad1.length(); c++){
		if (cad1[c] == '+')
			x++;
		else y++;

		if (cad2[c] == '+')
			a++;
		else
			if(cad2[c] == '-')
				b++;
			else
				n++;
	}

	if (a <= x && b <= y){
		i = x-a;
		j = y-b;
		
		res = (fact(n) / (fact(i) * fact(j))) / pow(2, n) ;
	}
	else res = 0.0;

	printf("%.12lf\n", res);
	return 0;
}