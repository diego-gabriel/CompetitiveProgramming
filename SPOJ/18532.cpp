#include <iostream>
#include <vector>

using namespace std;

bool exist(vector <int> &v, int valor, int &i){
	bool res = false;

	for (i = 0; i < v.size() && !res; i++){
		res = v[i] == valor;
	}
	i--;
	return res;
}

vector <int> sub(vector <int> &v, int ini, int size){
	vector <int> res;
	for (int i = ini; i < ini+size; i++){
		res.push_back(v[i]);
	}
	return res;
}

void print(vector <int> v){
	for (int i = 0; i < v.size(); i++)
		cout<<" "<<v[i];
	cout<<endl;
}

bool isTheSame(vector <int> pre, vector<int> post, vector<int>in){
	bool res;
/*
	cout<<"pre: "; 
	print(pre);
	cout<<"post: "; 
	print(post);
	cout<<"in: "; 
	print(in);
*/
	if (pre.empty() && post.empty() && in.empty())
		res = true;
	else{
		int posIn;
		int n = pre.size();
		if (pre[0] == post[n-1] && exist(in, pre[0], posIn)){
			int sizeL, sizeR;
			sizeL = posIn;
			sizeR = n-posIn-1;
			res = isTheSame(sub(pre, 1, sizeL), sub(post, 0, sizeL), sub(in, 0, sizeL)) 
			   && isTheSame(sub(pre, 1+sizeL, sizeR), sub(post, sizeL, sizeR), sub(in, sizeL+1, sizeR));
		}
		else
			res = false;
	}
	return res;
}

int main(){
	int n;
	while (cin>>n){
		vector <int> pre, post, in;
		int v;
		for (int i = 0; i < n; i++){
			cin>>v;
			pre.push_back(v);
		}
		for (int i = 0; i < n; i++){
			cin>>v;
			post.push_back(v);
		}
		for (int i = 0; i < n; i++){
			cin>>v;
			in.push_back(v);
		}

		if (isTheSame(pre, post, in))
			cout<<"yes"<<endl;
		else 
			cout<<"no"<<endl;
	}
}