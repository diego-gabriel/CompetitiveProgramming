#include <iostream>

using namespace std;

struct Node 
{
	long long sum;
	bool reverse;

	Node(){
		sum = 0;
		reverse = false;
	};
	int apply(int begin, int end){
		if (reverse)
			sum = (end - begin + 1) - sum;
		reverse = false;
	}
	void acum(){
		reverse = !reverse;
	}

	void join(Node a, Node z){
		sum = a.sum + z.sum;
		reverse = false;
	}
};


Node tree[30][4*100000 + 200];
int a[100000+5];

//init from #begin to #end, actual node is #i
void init(int id, int begin, int end, int i){
	if (begin == end){
		tree[id][i].sum = a[begin]>>id & 1;
	} else {
		int mid = (begin + end) / 2;
		int left = 2*i + 1;
		int right = 2*i + 2;

		init(id, begin, mid, left);
		init(id, mid+1, end, right);

		tree[id][i].join(tree[id][left], tree[id][right]);
	}
}


void propagate(int id, int begin, int end, int i){

	//if not a leaf, acumulate to children
	if (begin < end && tree[id][i].reverse){
		tree[id][2*i+1].acum();
		tree[id][2*i+2].acum();
	}
	//finally apply reverse
	tree[id][i].apply(begin, end);
}

Node get(int id, int begin, int end, int l, int r, int i){
	Node res;

	propagate(id, begin, end, i);

	if (l <= begin && end <= r){
		res = tree[id][i];
	} else {
		int mid = (begin+end)/2;
		int left = 2*i + 1;
		int right = 2*i + 2;
		if (r <= mid)
			res = get(id, begin, mid, l, r, left);
		else
		if (l > mid)
			res = get(id, mid+1, end, l, r, right);
		else{
			res = Node();
			res.join(get(id, begin, mid, l, mid, left), get(id, mid+1, end, mid+1, r, right));
		}
	}

	return res;
}


void update(int id, int begin, int end, int l, int r, int i){
	
	propagate(id, begin, end, i);

	if (l == begin && end == r){
		tree[id][i].acum();
		propagate(id, begin, end, i);

	} else {
		int mid = (begin+end)/2;
		int left = 2*i + 1;
		int right = 2*i + 2;
		
		if (r <= mid)
			update(id, begin, mid, l, r, left);
		else
		if (l > mid)
			update(id, mid+1, end, l, r, right);
		else {
			update(id, begin, mid, l, mid, left);
			update(id, mid+1, end, mid+1, r, right);
		}

		propagate(id, begin, mid, left);
		propagate(id, mid+1, end, right);
		tree[id][i].join(tree[id][left], tree[id][right]);
	}
}

int main(){

	int n, m; 
	cin>>n;

	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	cin>>m;

	for(int i = 0; i < 25; i++)
		init(i, 0, n-1, 0);

	int op, l, r, x;
	for (int i = 0; i < m; i++){
		cin>>op>>l>>r;

		if(op == 1){
			long long res = 0;
			for(int i = 0; i < 25; i++){

				res += (get(i, 0, n-1, l-1, r-1, 0).sum * (1LL<<i));
			}

			cout<<res<<endl;
		}
		else{
			cin>>x;
			for(int i = 0; i < 25; i++){
				if (x>>i & 1)
					update(i, 0, n-1, l-1, r-1, 0);
			}
		}

	}

	return 0;
}