#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Category
{
	set<int> courses;
	int minToPass;
	int taken;
	Category(){minToPass = 0; taken = 0; courses.clear();}

	void add(int c){
		courses.insert(c);
	}
	void read(){
		int n, c;
		cin>>n;
		cin>>minToPass;
		for (int i = 0; i < n; i++)
			cin>>c, add(c);

	}
	void take(int c){
		if (courses.find(c) != courses.end()){
			taken++;
		}
	}
	bool pass(){
		return taken >= minToPass;
	}
};


int main(){
	int taken, cat;
	while (cin>>taken && taken){
		cin>>cat;
		Category category[cat];
		int courses[taken];
		int passed = 0;
		for (int i = 0; i < taken; i++)
			cin>>courses[i];
		for (int i = 0; i < cat; i++){
			category[i].read();
			for (int j = 0; j < taken; j++){
				category[i].take(courses[j]);
			}
			if (category[i].pass())
				passed++;
		}

		if (cat == passed)
			cout<<"yes"<<endl;
		else 
			cout<<"no"<<endl;

	}
	return 0;
}