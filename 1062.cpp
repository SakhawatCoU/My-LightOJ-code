#include<bits/stdc++.h>
using namespace std;

double fun(double h1,double h2)
{
    return (1/h1)+(1/h2);
}

double BNS(double x,double y,double c)
{
    double l = 0.0,r = min(x,y);
    double mid;
    double h1,h2;
    for(int i=0;i<=100;i++)
    {
        mid = (l+r)/2.0;
        h1 = sqrt((x*x)-mid*mid);
        h2 = sqrt((y*y)-mid*mid);
        double ans = fun(h1,h2);
        if(ans<=(1.0/c))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return mid;
}


int main()
{
   int t;
   scanf("%d",&t);
   double x,y,c;
   for(int i=1;i<=t;i++)
   {
       scanf("%lf%lf%lf",&x,&y,&c);
       double ans = BNS(x,y,c);
      // cout<<ans<<endl;
       printf("Case %d: %0.9lf\n",i,ans);
   }
    return 0;
}
