#include <iostream>
#include <vector>

using namespace std;

struct Seg
{
	int a, b;
	Seg(){}
	Seg(int x, int y){
		a = x;
		b = y;
	}
	int gap(){
		return b-a;
	}
};

int main(){
	int n;
	cin>>n;
	Seg s[n];
	int best = -1;
	int gap = -1;	
	int a, b;
	for(int i = 0; i < n; i++){
		cin>>s[i].a>>s[i].b;

		if (s[i].gap() > gap){
			gap = s[i].gap();
			best = i;
		}
	}

	bool ok = true; 
	for(int i = 0; ok && i < n; i++){
		ok = s[best].a <= s[i].a && s[i].b <= s[best].b;
	}	

	if (ok)
		cout<<best+1<<endl;
	else
		cout<<-1<<endl;

	return 0;
}