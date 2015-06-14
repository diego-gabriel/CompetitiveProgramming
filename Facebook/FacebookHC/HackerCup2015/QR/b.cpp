#include <iostream>
#include <vector>

using namespace std;

struct Food
{
	int p, c, f;

	Food(){
		p = c = f = 0;
	};
	Food(int a, int b, int d){
		p = a;
		c = b;
		f = d;
	}
	void read(){
		cin>>p>>c>>f;
	}

	Food operator - (Food a){
		return Food(p-a.p, c-a.c, f-a.f);
	}
	Food operator + (Food a){
		return Food(p+a.p, c+a.c, f+a.f);
	}

	bool zero(){
		return p == 0 && c == 0 && f == 0;
	}
};



int main(){
	int t; 
	cin>>t;

	for (int test = 1; test <= t; test++){
		Food target;
		target.read();
		vector<Food> foods;
		int n;
		cin>>n;
		for (int i = 0; i < n; i++){
			Food aFood;
			aFood.read();
			foods.push_back(aFood);
		}

		int mask = 0;
		while (mask < (1<<n)){

			Food aFood;

			for (int i = 0; i < n; i++){
				if (mask & (1<<i)){
					aFood = aFood + foods[i];
				}
			}
	//		cout<<"mask: "<<mask<<endl;
	//		cout<<"food: "<<aFood.p<<" "<<aFood.c<<" "<<aFood.f<<endl;
			if ((target - aFood).zero())
				break;
			mask++;
		}

		cout<<"Case #"<<test<<": ";
		if (mask < (1<<n))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}