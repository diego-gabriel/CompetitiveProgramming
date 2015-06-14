#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Employee
{
	int hiredOn;
	int workUntil;
	int restUntil;

	Employee(){}
	Employee(int a, int b, int c){
		hiredOn = a;
		workUntil = b;
		restUntil = c;
	}
};

int main(){
	int n, m, k;
	cin>>n>>m>>k;

	vector<Employee> e;
	queue<Employee> working, resting;
	int nw = 0;	
	int day = 0;
	bool flag = true;
	while(flag){
		//cout<<"total hired: "<<e.size()<<endl;
		day++;
		//cout<<"--------- DAY "<<day<<" -----------"<<endl<<endl;
		//filling current day;
		while(nw < k){
			nw++;

			if(!resting.empty() && resting.front().restUntil < day){
				//cout<<"restUntil= "<< resting.front().restUntil<<endl;
				//cout<<"hiredOn 	= "<<resting.front().hiredOn<<endl;
				//cout<<"day 		= "<<day<<endl<<endl;
			}

			if(!resting.empty() && resting.front().restUntil < day){
				working.push(resting.front());
				if(resting.front().hiredOn == 1)
					flag = false;
				else
					resting.pop();
			} else { 
				Employee anEmp = Employee(day, day+n-1, day+n+m-1);
				e.push_back(anEmp);
				working.push(anEmp);
			//cout<<"   Hired a Employee On Day "<< day<<endl;
			}
		}

		//cout<<"filled"<<endl;
		//sending employees to rest

		if(!working.empty()){
				//cout<<"workUntil= "<< working.front().workUntil<<endl;
				//cout<<"hiredOn 	= "<<working.front().hiredOn<<endl;
				//cout<<"day 		= "<<day<<endl<<endl;
		}

		while(!working.empty() && working.front().workUntil == day){
			//cout<<"going to rest"<<endl;
			resting.push(working.front());
			working.pop();
			nw--;
		}

		if (working.empty()){
			nw++;

			if(!resting.empty() && resting.front().restUntil < day){
				//cout<<"restUntil= "<< resting.front().restUntil<<endl;
				//cout<<"hiredOn 	= "<<resting.front().hiredOn<<endl;
				//cout<<"day 		= "<<day<<endl<<endl;
			}

			if(!resting.empty() && resting.front().restUntil < day){
				working.push(resting.front());
				if(resting.front().hiredOn == 1)
					flag = false;
				else
					resting.pop();
			} else { 
				Employee anEmp = Employee(day, day+n-1, day+n+m-1);
				e.push_back(anEmp);
				working.push(anEmp);
				//cout<<"   Hired a Employee On Day "<< day<<endl;
			}
		}
		//cout<<"   -------------   "<<endl;
	}

	cout<<e.size()<<endl;
	cout<<e[0].hiredOn;

	for(int i = 1; i < e.size(); i++){
		cout<<" "<<e[i].hiredOn;
	}
	cout<<endl;

	return 0;
}