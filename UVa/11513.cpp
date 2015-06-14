#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

vector<short> moverHorizontal(vector <short> v, int i)
{
	i = 3*(i-1) + 1;
	
	swap(v[i], v[i+1]);
	swap(v[i+1], v[i+2]);
	return v;
}

vector <short> moverVertical(vector <short> v, int i)
{
	swap(v[i+6], v[i+3]);
	swap(v[i+3], v[i]);
	return v;
}
struct Camino
{
	stack <pair<char, short> > camino;
	bool ok;
	
	Camino(){};
	
	void add(char k, short i)
	{
		camino.push(make_pair(k, i));
	}
	
	void print()
	{
		if (camino.empty())
		{
			cout<<"Not solvable"<<endl;
		}
		else
		{
			cout<<camino.size()<<" ";
			while(!camino.empty())
			{
				cout<<camino.top().first<<camino.top().second;
				camino.pop();
			}
			cout<<endl;
		}
	}
	
};



map<vector <short>, Camino> visitado;

void calc()
{

	vector <short> origen, destino;
	vector <short> target;
	
	for (int i = 0; i < 10; i++)
		target.push_back(i);
	queue <vector <short> > cola;
	
	visitado[target].ok = true;
	cola.push(target);
	int p = 0;
	long long in = 0;
	while (!cola.empty())
	{
		in++;
		origen = cola.front();
		cola.pop();
		
		
		Camino camino = visitado[origen];
		for (short i = 0; i < 3; i++)
		{
			destino = moverHorizontal(origen, i+1);
			Camino cam = visitado[destino];
			if (!cam.ok)
			{
				cam = camino;
				cam.add('H', i+1);
				cola.push(destino);
				visitado[destino] = cam;
				p++;
			}
		}
		for (short i = 0; i < 3; i++)
		{
			destino = moverVertical(origen, i+1);
			Camino cam = visitado[destino];
			if (!cam.ok)
			{
				cam = camino;
				cam.add('V', i+1);
				cola.push(destino);
				visitado[destino] = cam;
			p++;
			}
		}
	}
	
	cout<<p<<endl<<in<<visitado.size()<<endl;
}

int main()
{
	int n;
	
	calc();
	cout<<"ok!"<<endl;
	while (cin>>n && n)
	{
		vector <short> cubo(10);
		
		
		cubo[1] = n;
		for (short i = 2; i < 10; i++)
			cin>>cubo[i];
			
		Camino r = visitado[cubo];
		
		r.print();
		
	}
}
