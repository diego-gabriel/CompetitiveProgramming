#include <iostream>
#include <cmath>
#include <cstdio>
 
using namespace std;
 
int p, q, r, s, t, u;
 
float eval(float x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2.0f) + u;
}
 
int main() 
{
 
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) 
    {
        double low = 0.0;
        double high = 1.0;
        double mid, emid, ehigh;

        while(high - low > 0.0000001) 
        {
            mid = (low + high) / 2.0;
            emid = eval(mid), ehigh = eval(high);
          //  cout<<emid<<endl;
            if((ehigh < 0 && emid > 0) || (ehigh > 0 && emid < 0) || (ehigh >= 0 && emid > ehigh))
            {
                low = mid;
            } 
            else
            {
                high = mid;
            }
        }
 
        if(fabs(emid) <= 0.0001)
            printf("%.4f\n", mid);
        else
            printf("No solution\n");
    }
 
    return 0;
}