#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;


int main(){
	int test;
	cin>>test;
	int nTab, nOrd;
	while (test--){
		cin>>nTab>>nOrd;
		int tabs[nTab];
		memset(tabs, 0, sizeof(tabs));
		int orders[nOrd];
		queue<int> caux;
		vector <queue<int> > colas(401, caux);

		for (int i = 0; i < nOrd; i++){
			cin>>orders[i];
			colas[orders[i]].push(i);
		}

		int currOrd;
		int cantTabs = nTab;
		int res = 0;
		for (int i = 0; i < nOrd; i++){
			currOrd = orders[i];
			colas[currOrd].pop();
			bool allocated = false;
			for (int j = 0; j < nTab && !allocated; j++){
				if (tabs[j] == 0){
					res++;
					tabs[j] = currOrd;
					allocated = true;
				}
				else
					allocated = tabs[j] == currOrd;
			}

			if (!allocated){
				int cusInTab;
				int canditateTab;
				int best = 0;

				for (int j = 0; j < nTab; j++){
					cusInTab = tabs[j];
					if (colas[cusInTab].empty()){
						canditateTab = j;
						break;
					}
					else
					{
						if (best < colas[cusInTab].front()){
							best = colas[cusInTab].front();
							canditateTab = j;
						}
					}
				}

				res++;
				tabs[canditateTab] = currOrd;

			}
		}
		cout<<res<<endl;
	}
	return 0;
}