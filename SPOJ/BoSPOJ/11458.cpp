#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	unsigned long long n, a, b, c, d;
	while (cin>>n>>a>>b>>c>>d){
		if (n == 0 && a == 0 && b == 0 && c == 0 && d == 0)
			break;

		if (a % n == 0 && b % n == 0 && c % n == 0 && d % n == 0)
		{
			a /= n;
			b /= n; 
			c /= n;
			d /= n;

			unsigned long long t[4];
			t[0] = a;
			t[1] = b;
			t[2] = c;
			t[3] = d;

			sort(t, t+4);

			bool ok = false;
			
			if ((t[3] + t[2]) % n == 0 && (t[0] + t[1]) % n == 0){
				ok = n == ((t[3] + t[2]) / n) + ((t[1] + t[0]) / n);
				if (ok){
					int x = ((t[3] + t[2]) / n);
					int y = ((t[1] + t[0]) / n);
					//cout<<x<<" --- "<<y<<endl;
					ok = t[3] % x == 0 && t[2] % x == 0 && t[1] % y == 0 && t[0] % y == 0;
				}
			}

			if (ok)
				cout<<"Possible"<<endl;
			else cout<<"Impossible"<<endl;

		}
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}