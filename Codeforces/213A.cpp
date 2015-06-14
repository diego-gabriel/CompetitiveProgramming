#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int dist[4][4];
map <int, set <int> > grafo;
map <int, set <int> > :: iterator ig;

int main()
{
	int n;

	cin>>n;

	int ID[n+1];
	bool act[4];
	act[0] = act[1] = act[2] = act[3] = false;
	for (int i = 1; i <= n; i++)
	{
		cin>>ID[i];
		act[ID[i]] = true;
	}

	int nP, p;
	set <int> inits;
	for (int i = 1; i <= n; i++)
	{
		cin>>nP;
		for (int k = 0; k < nP; k++)
		{
			cin>>p;
			grafo[i].insert(p);
		}

		if (!nP) inits.insert(i);
	}

	int bestRes = 0x0fffffff;
	set <int> :: iterator it, ip;
	set <int> axin = inits;

		map <int, set<int> > auxg = grafo;
	for (ip = axin.begin(); ip != axin.end(); ip++)
	{
		//cout<<"AAAJ: "<<*ip<<endl;
		int res = 0;
		int c = ID[*ip];
		int notCompleted = n;
		map <int, bool> done;
		bool fst = true;
		inits = axin;
		grafo = auxg;
		while (notCompleted)
		{
			set <int> aux;
			bool none = true;
			while (!inits.empty())
			{
				if (!fst)
					it = inits.begin();
				else 
				{
					fst = false;
					it = inits.find(*ip);
					//cout<<*ip<<" num: "<<*it<<endl;
				}
				if (done[*it] || ID[*it] != c)
				{
					aux.insert(*it);
					inits.erase(*it);
					continue;
				}
		//		cout<<"realizando: "<<*it<<" en maquina: "<<c<<endl;
				none = false;
				done[*it] = true;
				notCompleted--;

				for (int i = 1; i <= n; i++)
				{
					if (!done[i])
					{
						grafo[i].erase(*it);
						if (grafo[i].empty()){
							aux.insert(i);
		//					cout<<"desbloqueada tarea: "<<i<<endl;
						}
					}
				}
				inits.erase(*it);
			}

			inits = aux;
			if (none) {
				 
				c = (c % 3) + 1;
				res++;
			}
		}
		//cout<<res<<" "<<bestRes<<endl;

		bestRes = min(res, bestRes);
	}
	cout<<bestRes + n<<endl;

	return 0;
}