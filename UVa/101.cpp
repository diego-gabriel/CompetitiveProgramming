#include <iostream>
#include <cstring>

using namespace std;

int bw[25][25];
int dn[25];

struct Pos
{
	int x;
	int y;
	Pos(){};
	Pos(int a, int b){
		x = a;
		y = b;
	}
};

Pos pa, pb;

void clear(){
	for (int i = 0; i < 25; i++){
		for (int j = 0; j < 25; j++){
			bw[i][j] = -1;
		}
		bw[i][0] = i;
	}
}

Pos find(int aBlock){
	int j, i;
	i = j = 0;

	while (bw[i][j] != aBlock){
		j++;
		i += (j/25),
		j %= 25;
	}

	return Pos(i, j);
}

Pos find_top(Pos p){
	while (bw[p.x][p.y] != -1){
		p.y++;
	}
	return p;
}

bool validate_command(int a, int b){
	return a != b && pa.x != pb.x;
}

void return_all_over(Pos pos){

	int j = pos.y+1;

	while (bw[pos.x][j] != -1){
		int otherBlock = bw[pos.x][j];
		bw[pos.x][j] = -1;
		bw[otherBlock][0] = otherBlock;
		j++;
	}
}

void print(int n){
	for (int i = 0; i < n; i++){
			cout<<i<<":";
			int j = 0;
			while (bw[i][j] != -1){
				cout<<" "<<bw[i][j];
				j++;
			}
			cout<<endl;
		}
}

int main(){
	int n;
	while (cin>>n){
		string cmd1, cmd2;
		int a, b;
		Pos ptop;
		clear();
		while (cin>>cmd1 && cmd1 != "quit"){
			cin>>a>>cmd2>>b;	
			pa = find(a);
			pb = find(b);
			if (!validate_command(a, b))
				continue;
			if (cmd1 == "move"){
				if (cmd2 == "onto"){
					return_all_over(pa);
					return_all_over(pb);
					bw[pa.x][pa.y] = -1;
					bw[pb.x][pb.y+1] = a;
				}
				if (cmd2 == "over"){
					return_all_over(pa);
					ptop = find_top(pb);
					bw[pa.x][pa.y] = -1;
					bw[ptop.x][ptop.y] = a;
				}
			}	

			if (cmd1 == "pile"){
				if (cmd2 == "onto"){
					return_all_over(pb);
					ptop = find_top(pa);
					int file = pa.x;
					pb.y++;
					for (int i = pa.y; i < ptop.y; i++){
						int aBlock = bw[file][i];
						bw[file][i] = -1;
						bw[pb.x][pb.y] = aBlock;
						pb.y++;
					}

				}
				if (cmd2 == "over"){
					pb = find_top(pb);
					ptop = find_top(pa);
					int file = pa.x;
					for (int i = pa.y; i < ptop.y; i++){
						int aBlock = bw[file][i];
						bw[file][i] = -1;
						bw[pb.x][pb.y] = aBlock;
						pb.y++;
					}					
				}
			}
		//	cout<<cmd1<<" "<<a<<cmd2<<b<<" performed"<<endl;
			//print(n);
		}

		print(n);
	}
	return 0;
}