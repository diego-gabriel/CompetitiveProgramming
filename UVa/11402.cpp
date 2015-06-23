#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	int buccaneer;
	int size;
	queue<char>ops;
	Node(){
		buccaneer = 0;
		size = 0;
	}

	void join(Node a, Node b){
		buccaneer = a.buccaneer + b.buccaneer;
		size = a.size + b.size;
	}

	void accum(char op){
		ops.push(op);
	}

	void accum(queue<char> op){
		while(!op.empty()){
			ops.push(op.front());
			op.pop();
		}
	}
	void apply(){
		char op;
		while(!ops.empty()){
			op = ops.front();
			ops.pop();

			if (op == 'F')
				buccaneer = size;
			if (op == 'E')
				buccaneer = 0;
			if (op == 'I')
				buccaneer = size - buccaneer;
		}
	}
};

vector<Node> tree;
string a;

void init(int begin, int end, int i){
	
	if (begin == end){
		tree[i].buccaneer = a[begin] == '1';
		tree[i].size = 1;
		tree[i].ops = queue<char>();
	} else {
		int mid = (begin + end) / 2;
		int left = 2*i + 1;
		int right = 2*i + 2;

		init(begin, mid, left);
		init(mid+1, end, right);

		tree[i].join(tree[left], tree[right]);
	}
}

void propagate(int begin, int end, int i){
	//not a leaf
	if (begin < end){
		tree[i*2+1].accum(tree[i].ops);
		tree[i*2+2].accum(tree[i].ops);
	}
	tree[i].apply();
}

Node get(int begin, int end, int l, int r, int i){
	Node res;
	
	propagate(begin, end, i);

	if (l == begin && end == r){
		res = tree[i];
	} else {
		int mid = (begin + end) / 2;
		int left = 2*i + 1;
		int right = 2*i + 2;

		if (r <= mid){
			res = get(begin, mid, l, r, left);
		}
		else
		if (l > mid){
			res = get(mid+1, end, l, r, right);
		} else {
			res = Node();
			res.join(get(begin, mid, l, mid, left), get(mid+1, end, mid+1, r, right));
		}
	}

	return res;
}

void update(int begin, int end, int l, int r, int i, char op){
	propagate(begin, end, i);
	//cout<<"u "<<begin<<" "<<end<<" "<<i<<endl; 
	if (l == begin && end == r){
		tree[i].accum(op);
		propagate(begin, end, i);
	} else {
		int mid = (begin + end) / 2;
		int left = 2*i + 1;
		int right = 2*i + 2;

		if (r <= mid){
			update(begin, mid, l, r, left, op);
		} else
		if (l > mid){
			update(mid+1, end, l, r, right, op);
		} else {
			update(begin, mid, l, mid, left, op);
			update(mid+1, end, mid+1, r, right, op);
		}

		propagate(begin, mid, left);
		propagate(mid+1, end, right);
		tree[i].join(tree[left], tree[right]);
	}
}

int main(){

	int n;
	tree.assign(4*1024000, Node());
	int t;
	cin>>t;
	string cad;
	while(t--){
		cad = "";
		int m;
		cin>>m;
		while (m--){
			cin>>n>>cad;
			while(n--){
				a = a + cad;
			}
		}
		
		int q;
		cin>>q;
		int l, r;
		char op;
		n = a.size();
		init(0, a.size()-1, 0);

		for(int i = 0; i < q; i++){
			cin>>op>>l>>r;

			if(op == 'S'){
			//	cout<<"executing "<<op<<endl;
				cout<<get(0, n-1, l, r, 0).buccaneer<<endl;
			//	cout<<"ended"<<endl;
			} else {
			//	cout<<"Updating... "<<endl;
				update(0, n-1, l, r, 0, op);
			//	cout<<"updated"<<endl;
			}
		}
	}
	return 0;
}