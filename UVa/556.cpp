#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

vector <string> maze;
vector <vector <int> > count;

string build(int n){
	string res = "";
	for (int i = 0; i <n; i++){
		res = res + "1";
	}
	return res;
}

struct Dir
{
	int x, y;
	Dir(){
		x = 0;
		y = 1;
	}


	void turnLeft(){
		int a = x;
		x = -y;
		y = a;
	}
	void turnRight(){
		int a = x;
		x = y;
		y = -a;
	}
};

struct Robot
{
	int x, y;
	Dir d;
	Robot(){};
	Robot(int a, int b){
		x = a;
		y = b;
		d = Dir();
	}

	void turnLeft(){
//		cout<<"turned left"<<endl;
		d.turnLeft();
	}
	void turnRight(){
//		cout<<"turned right"<<endl;
		d.turnRight();
	}

	void moveTo(int a, int b){
		count[x][y]++;
		x = a;
		y = b;
//		cout<<endl<<"moved to"<<x<<" "<<y<<endl;
	}

	void checkRight(){
		Dir od = d;
		od.turnRight();
		if (maze[x+od.x][y+od.y] == '0'){

	//		cout<<endl<<"-------- Rigth is not a wall ("<<x+od.x<<" "<<y+od.y<<")-------"<<endl;
			d.turnRight();
			moveTo(x+d.x, y+d.y);
		}
	}

	bool advance(){
		int nx, ny;
		nx = x+d.x;
		ny = y+d.y;

//		cout<<"advancing to "<<nx<<" "<<ny;
		bool res;
		if (maze[nx][ny] == '0'){
			moveTo(nx, ny);
			res = true;
	//		cout<<"before check "<<maze.size()-2<<endl;
			if (x != maze.size()-2 || y != 1)
				checkRight();

		}
		else
			res = false;
	//	if (res)
	//		cout<<" succesfull"<<endl;
	//	else
	//		cout<<" rejected"<<endl;
		return res;
	}

	void move(){
//		cout<<"moving "<<x<<" "<<y<<endl;
		while (!advance()){
			turnLeft();
		}
//		cout<<"        exit moving"<<endl;
	}

};

int main(){

	int n, m;
	while (cin>>n>>m && (n || m)){
		string cad;
		maze.clear();
		count.clear();
		Robot r = Robot(n, 1);
		maze.push_back(build(m+2));

		count.assign(n+2, vector<int>(m+2, 0));

		for (int i = 0; i < n; i++){
			cin>>cad;
			maze.push_back("1"+cad+"1");
		}
		maze.push_back(build(m+2));

		do{
			r.move();
		} while (r.x != n || r.y != 1);

		int res[5];
		memset(res, 0, sizeof(res));

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (count[i][j] < 5 && maze[i][j] == '0'){
					res[count[i][j]]++;
				}
			}
		}
//		cout<<"here"<<endl;

		printf("%3d%3d%3d%3d%3d\n", res[0], res[1], res[2], res[3], res[4]);
		
	}
	return 0;
}