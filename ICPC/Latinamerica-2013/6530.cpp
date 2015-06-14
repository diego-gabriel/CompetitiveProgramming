#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Partido
{
	int s, r;
	Partido(int a, int b){
		s = a;
		r = b;
	}
};

Partido read(){
	int a, b;
	cin>>a>>b;
	return Partido(a, b);
}

bool ord(Partido a, Partido b){
	return a.s-a.r > b.s-b.r;
}

int main(){

	int n, g;
	bool fst = true;
	while(cin>>n>>g){

		vector<Partido> p;
		for (int i = 0; i < n; i++){
			p.push_back(read());
		}

		sort(p.begin(), p.end(), ord);
		int i = 0;
		int t = 0;
		while (i < p.size()){
			if (p[i].s-p[i].r > 0)
				t +=3;
			else
			if (p[i].s-p[i].r == 0 && g){
				t+=3;
				g--;
			}
			else{
				if (p[i].s-p[i].r + g > 0){
					g += (p[i].s-p[i].r-1);
					t+=3;
				}
				else
				if (p[i].s-p[i].r + g== 0){
					g = 0;
					t+= 1;
				}
			}
			i++;
		}
		cout<<t<<endl;
	}
	return 0;
}