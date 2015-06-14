#include <iostream>
#include <set>

using namespace std;

long long R[505][505];
long long C[505][505];
long long P[505][505];
long long distancia[505][505];

long long min(long long a, long long b){
	return a < b ? a : b;
}
long long max(long long a, long long b){
	return a > b ? a : b;
}

struct Position
{
	long long r, c;
	Position(){
		r = c = 0;
	}

	Position(long long a, long long b){
		r = a;
		c = b;
	}

	void read(){
		cin>>r>>c;
		r--;
		c--;
	}

	long long rP(){
		return R[r][c];
	}
	long long cP(){
		return C[r][c];
	}

	bool goOutside(Position other, long long maxR, long long maxC){

		bool res = max(0, other.r - other.rP()) > max(0, r - rP()) || min(maxR, other.r + other.rP()) < min(maxR, r + rP())
				|| max(0, other.c - other.cP()) > max(0, c - cP()) || min(maxC, other.c + other.cP()) < min(maxC, c + cP());

	//	printTo(other);
	//	cout<<(res ? "goOutside" : "still inside")<<endl;
		return res;
	}

	void print(){
		cout<<"("<<r<<", "<<c<<")";
	}
	void printTo(Position t){
		print();
		cout<<" -> ";
		t.print();
		cout<<endl;
	}
};

struct Node
{
	Position pos;
	long long dist;

	Node(){dist = 0x0fffffff; pos = Position();};
	Node(Position p, long long d){
		pos = p;
		dist = d;
	}
};


Position list[5];
long long r, c, n;

bool operator < (Position a, Position b){
	if (a.r == b.r && b.goOutside(a, r, c))
		return a.c < b.c;
	return a.r < b.r;
}

bool operator < (Node a, Node b){
	if (a.dist == b.dist){
		return a.pos < b.pos;
	}
	return a.dist < b.dist;
}


void readInput(){
	for (long long i = 0; i < r; i++){
		for (long long j = 0; j < c; j++){
			cin>>P[i][j];
			distancia[i][j] = 0x0fffffff;
		}
	}
	for (long long i = 0; i < r; i++){
		for (long long j = 0; j < c; j++){
			cin>>R[i][j];
		}
	}
	for (long long i = 0; i < r; i++){
		for (long long j = 0; j < c; j++){
			cin>>C[i][j];
		}
	}
	for (long long i = 0; i < n; i++){
		list[i].read();
	}
}

long long distanceTo(Position aPos){
	return distancia[aPos.r][aPos.c];
}
Node distanceTo(Position aPos, long long a){
	return Node (aPos, distancia[aPos.r][aPos.c] = a);
}

long long solve(Position source, Position target){
	//cout<<"\n\n\n-------------------\nINICIO\n----------------------\n\n";
	
	Node tNode;
	set<Node> cola;
	Node sNode = distanceTo(source, 0);
	cola.insert(sNode);
	long long x, y;
	Position destiny;
//	source.printTo(target);

	while (!cola.empty()){
		sNode = *(cola.begin());
		cola.erase(cola.begin());
		x = sNode.pos.r;
		y = sNode.pos.c;
		source = sNode.pos;
	/*	cout<<"hello ";;
		source.print();
		cout<<endl;
		cout<<"R: "<<R[x][y]<<endl;
		cout<<"C: "<<C[x][y]<<endl;
	*/	for (long long i = max(0, x - R[x][y]); i <= min(r-1, x + R[x][y]); i++){
			for (long long j = max(0, y - C[x][y]); j <= min(c-1, y + C[x][y]); j++){
				destiny = Position(i, j);
	//			cout<<"trying "; destiny.print(); cout<<endl;
				if (distanceTo(source) + P[x][y] < distanceTo(destiny)){
					tNode = distanceTo(destiny, distanceTo(source)+P[x][y]);
	//				cout<<"best distance found for ";
	//				destiny.print();
	//				cout<<" now is: "<<distanceTo(destiny);
	//				cout<<endl;
					if (destiny.goOutside(source, r, c))
						cola.insert(tNode);
				}
			}
		}
	}


	return distanceTo(target) == 0x0fffffff ? -1 : distanceTo(target);
}

void clear(){
	for (long long i = 0; i < r; i++){
		for (long long j = 0; j < c; j++){
			
			distancia[i][j] = 0x0fffffff;
		}
	}
}

int main(){
	
	while (cin>>r>>c>>n){
		readInput();
		
		for (long long i = 1; i < n; i++){
			clear();

			if (i != 1)
				cout<<" ";
			cout<<solve(list[i-1], list[i]);
		}
		cout<<endl;

	}
	return 0;
}