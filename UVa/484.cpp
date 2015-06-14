#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int number;
	int id;
	int times;

	Data(){};
	Data(int n, int d){
		number = n;
		id = d;
		times = 0;
	}

	void add(){
		times++;
	}
	void print(){
		cout<<number<<" "<<times<<endl;
	}
};

bool operator < (Data a, Data b){
	return a.id < b.id;
}

int main(){

	map <int, Data> numbers;
	map <int, Data> :: iterator it;
	int n;
	int id = 1;
	while(cin>>n){

		if (numbers.find(n) == numbers.end()){
			numbers[n] = Data(n, id);
			id++;
		}

		numbers[n].add();
	}

	vector <Data> res;

	for(it = numbers.begin(); it != numbers.end(); it++){
		res.push_back(it->second);
	}

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++){
		res[i].print();
	}


	return 0;
}