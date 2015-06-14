#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 100005

int h[MAX], l[MAX], r[MAX];
struct Node
{
	int min;
	Node(){};
	Node(int n){
		min = n;
	}
} tree[4*MAX];

void init(int node, int l, int r){
	if (l == r){
		tree[node].min = l;
	}
	else{
		int mid = (l+r) / 2;
		init(node*2+1, l, mid);
		init(node*2+2, mid+1, r);

		Node lef = tree[node*2+1];
		Node rig = tree[node*2+2];

		if (h[lef.min] < h[rig.min])
			tree[node].min = lef.min;
		else
			tree[node].min = rig.min;
	}
}


Node query(int node, int l, int r, int i, int j){
	if (i == l && j == r)
		return tree[node];
	else{
		int mid = (l+r) / 2;
		if (j <= mid)
			return query(node*2+1, l, mid, i, j);
		else
		if (i > mid)
			return query(node*2+2, mid+1, r, i, j);
		else{
			Node lef = query(node*2+1, l, mid, i, mid);
			Node rig = query(node*2+2, mid+1, r, mid+1, j);

			Node res;

			if (h[lef.min] < h[rig.min])
				res.min = lef.min;
			else
				res.min = rig.min;		

			return res;
		}
	}
}




void init(int n){
	init(0, 0, n-1);
}

Node query(int a, int b, int n){
//	cout<<"query "<<a<<" - "<<b<<endl;
	Node res = query(0, 0, n-1, a, b);
//	cout<<"end of query "<<res.min<<endl;
	return res;
}

int f(int a, int b, int n){
//	cout<<"f on: "<<a<<" - "<<b<<endl;
	if (b == -1)
		return h[a];
	else{
		int i = a;
		if (a > b)
			swap(a, b);
		Node node = query(a, b, n);
//		cout<<h[i]<<" - "<<h[node.min]<<endl;
		return h[i] - h[node.min];
	}
}


int main(){

	int n;
	while (cin>>n){
		for (int i = 0; i < n; i++){
			cin>>h[i];
		}
		init(n);

		bool flag;
		int last;

		flag = false;
		last = -1;
		for (int i = 1; i < n-1; i++){
			if (h[i] > h[i-1] && h[i] > h[i+1]){
				if (flag){
					int current = last;
					while (current != -1 && h[current] <= h[i]){
						current = l[current];
					}
					l[i] = current;
				}
				else{
					flag = true;
					l[i] = -1;
				}

				last = i;
			}
			else
				l[i] = -2;
		}


		flag = false;
		last = -1;

		for (int i = n-2; i > 0; i--){
			if (h[i] > h[i-1] && h[i] > h[i+1]){
				if (flag){
					int current = last;
					while (current != -1 && h[current] <= h[i]){
						current = r[current];
					}
					r[i] = current;
				}
				else{
					flag = true;
					r[i] = -1;
				}

				last = i;
			}
			else
				r[i] = -2;
		}

		vector <int> res;
		for (int i = 1; i < n-1; i++){
			if (l[i] != -2 && l[i] != -2){
				if (f(i, l[i], n) >= 150000 && f(i, r[i], n) >= 150000)
					res.push_back(i);
			}
		}

		cout<<res[0]+1;
		for (int i = 1; i < res.size(); i++)
			cout<<" "<<res[i]+1;
		cout<<endl;
	}

	return 0;
}