#include <iostream>

using namespace std;

int max(int a, int b){
	return a > b ? a : b;
}

struct P
{	
	int p, t;
	P(){
	}
	P(int a, int b){
		p = a;
		t = b;
	}

	int val(){
		return max(3*p / 10, p - (p/250)*t);
	}
};

int main(){
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	P v, m;
	m = P(a, c);
	v = P(b, d);

	int p1 = m.val();
	int p2 = v.val();

	if (p1 > p2)
		cout<<"Misha"<<endl;
	else
	if (p2 > p1)
		cout<<"Vasya"<<endl;
	else
		cout<<"Tie"<<endl;

	return 0;
}