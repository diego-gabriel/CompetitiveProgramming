#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char grid[105][105];
int res;

struct Point
{
	int x, y;
	Point(){}
	Point(int a, int b){
		x = a;
		y = b;
	}

};

Point dir(char k){
//	cout<<"dir for "<<k<<endl;
	if (k == '^')
		return Point(-1, 0);
	if (k == '>')
		return Point(0, 1);
	if (k == 'v')
		return Point(1, 0);
	if (k == '<')
		return Point(0, -1);
}

bool isDir(char k){
	return k == '<' || k == '^' || k == '>' || k == 'v';
}

Point next(int i, int j, Point d){
//	cout<<"   dir x: "<<d.x<<" y: "<<d.y<<endl;
	i += d.x;
	j += d.y;
	while (grid[i][j] != '*' && grid[i][j] != '$' && !isDir(grid[i][j])){
		i += d.x;
		j += d.y;
//		cout<<"		at x:"<<i<<" y: "<<j<<endl;
	}
	return Point(i, j);
}

//if 1 change, 0 ok, -1 impossible
int check(int i, int j){
	int res = 0;
	Point d = dir(grid[i][j]);
	Point pNext = next(i, j, d);
	//if goes out
	if (grid[pNext.x][pNext.y] == '*'){
		res = -1;
	} else {
		Point last = Point(i, j);
		grid[i][j] == '$';
		Point nn = pNext;

		while (isDir(grid[nn.x][nn.y])){
			pNext = nn;
	//		cout<<"on x: "<<nn.x<<" y: "<<nn.y<<" car: "<<grid[nn.x][nn.y]<<endl;
			nn = next(pNext.x, pNext.y, dir(grid[pNext.x][pNext.y]));
			
			grid[pNext.x][pNext.y] = '$';
	//		cout<<"next x: "<<nn.x<<" y: "<<nn.y<<endl;
		}
	//	cout<<"out on "<<grid[pNext.x][pNext.y]<<endl;
		if (grid[nn.x][nn.y] != '$')
			res = 1;

	}

	return res;
}

void solve(int test){
	int r, c;
	cin>>r>>c;
	memset(grid, '*', sizeof(grid));
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++){
			cin>>grid[i][j];
		}
	res = 0;
	bool pos = true;
	char dd[4];
	dd[0] = '^';
	dd[1] = '>';
	dd[2] = '<';
	dd[3] = 'v';
	for (int i = 1; i <= r && pos; i++){
		for (int j = 1; j <= c && pos; j++){
			if (grid[i][j] != '.' && grid[i][j] != '$'){
				char was = grid[i][j];
				int response = check(i, j);
				pos = false;
				if (response == -1){
					for (int k = 0; k < 4; k++){
						if (dd[k] == was) continue;
						grid[i][j] = dd[k];
						response = check(i, j);
						if (response >= 0){
							pos = true;
							if (response == 0){
								res++;
							}
							if (response > 0){
								res += 2;
							}

							break;
						}
					}
				}
				else if(response > 0){
					res++;
					pos = true;
				}
				else
					pos = true;
			}
		}
	}
	if (pos)
		cout<<"Case #"<<test<<": "<<res<<endl;
	else
		cout<<"Case #"<<test<<": IMPOSSIBLE"<<endl;
}

int main(){
	int t;
	cin>>t;
	for (int test = 1; test <= t; test++){
		solve(test);
	}
	return 0;
}