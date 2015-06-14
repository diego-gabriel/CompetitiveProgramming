#include <iostream>
#include <cmath>

using namespace std;

#define Semilla Vector

struct Vector
{
	double x, y;
	Vector()
	{}

	Vector(double a, double b)
	{
		x = a;
		y = b;
	}
};

struct Lazamiento
{
	double xi, yi, xf, yf, r;
	Vector dir;

	Lazamiento(double x, double y, double ra, double dx, double dy, double t)
	{
		xi = x;
		yi = y;

		xf = x + t*dx;
		yf = y + t*dy;

		r = ra;

		dir = Vector(dx, dy);
	}

	Lazamiento(){};

};

bool toca(Lazamiento l, Semilla s)
{
	bool res = true;

	return res;
}


int main()
{
	int n;

	cin>>n;

	for (int caso = 1; caso <= n; caso++)
	{
		int nL, nS;
		cin>>nL>>nS;

		Lazamiento lanzamientos[nL];
		Semilla semillas[nS];
		bool tocada[nS];
		double x, y, r, dx, dy, t;
		for (int i = 0; i < nL; i++)
		{
			cin>>x>>y>>r>>dx>>dy>>t;
			lanzamientos[i] = Lazamiento(x, y, r, dx, dy, t);
		}

		for (int i = 0; i < nS; i++)
		{
			cin>>x>>y;
			semillas[i] = Semilla(x, y);
			tocada[i] = false;
		}

		int res = 0;

		for (int i = 0; i < nL; i++)
		{
			for (int j = 0; j < nS; j++)
			{
				if (!tocada[j] && toca(lanzamientos[i], semillas[j]))
				{
					res++;
					tocada[j] = true;
				}

			}
		}

		cout<<"Caso "<<caso<<": "<<res<<endl;

	}
	return 0;
}