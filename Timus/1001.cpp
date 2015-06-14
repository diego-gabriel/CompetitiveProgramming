#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
	long long n;
	stack <long long> pila;
	while (cin>>n)
	{
		pila.push(n);
	}

	while (!pila.empty())
	{
		n = pila.top();
		pila.pop();
		printf("%.4f\n", sqrt(n));
	}

	return 0;
}