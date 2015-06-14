#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> vis;
vector<int> match;
vector< vector<int> > grafo;

char mat[101][101];
int fake_mat[101][101];

int Aug(int act)
{
	if(vis[act])
		return 0;
	vis[act] = 1;
	for(int j = 0; j < grafo[act].size(); j++)
	{
		int r = grafo[act][j];
		if(match[r] == -1 || Aug(match[r]))
		{
			match[r] = act;
			return 1;
		}
	}
	return 0;
}

int N;	

void mostrar()
{
	cout<<endl;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout<<mat[i][j]<<" ";	
		}
		cout<<endl;
	}

	cout<<endl;


	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout<<fake_mat[i][j]<<" ";	
		}
		cout<<endl;
	}
}

void init()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			fake_mat[i][j] = -1;	
		}
	}
}


int main()
{
	int fil, col;
	while(cin>>N)
	{
		init();
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				cin>>mat[i][j];	
			}
		}

		fil = col = -1;

		for(int i = 0; i < N; i++)
		{
			if(mat[i][0] != 'X')
				fil++;
			for(int j = 0; j < N; j++)
			{
				if(mat[i][j] == '.')
				{
					fake_mat[i][j] = fil;
				}
				else if((mat[i][j] == 'X') && (j+1 < N) && (mat[i][j+1] == '.'))
				{
					fil++;
				}
			}
		}

		vector<int> dummy;
		grafo.assign(fil + 1, dummy);
		col = fil;

		for(int j = 0; j < N; j++)
		{
			if(mat[0][j] != 'X')
				col++;
			for(int i = 0; i < N; i++)
			{
				if(mat[i][j] == '.')
				{	
					grafo[fake_mat[i][j]].push_back(col);
				}
				else if((mat[i][j] == 'X') && (i+1 < N) && (mat[i+1][j] == '.'))
				{
					col++;
				}	
			}
		}

		int MCBM = 0;

		match.assign(fil+ col +6, -1);
		for(int i = 0; i < fil+1; i++)
		{
			vis.assign(fil+1, 0);
			MCBM += Aug(i);
		}
		cout<<MCBM<<endl;			
	}
	return 0;
}