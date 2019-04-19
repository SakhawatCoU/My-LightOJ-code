#include<bits/stdc++.h>
#define lli long long int
#define scf(n) scanf("%lld",&n)
#define rep1(n) for(int i=1;i<=n;i++)
#define prf(n) printf("%lld",n)
#define sci(n) scanf("%d",&n)
#define pri(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define scl(n) scanf("%lld",&n)
#define nl printf("\n")
#define spc printf(" ")
#define file freopen("in.txt","rt",stdin)
#define pii pair<char,char>
#define piii pair<pii,int>
using namespace std;
 
/*bool sortBySec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}*/
 
int sum[1000009];
int sum1[1000009];
 
void numberOfzero()
{
    for(int i=1; i<=1000009; i+=1)
    {
        int x = i;
        int cnt = 0;
        while(x>0)
        {
            int r = x%5;
            if(r==0)
                cnt++;
            else
                break;
            x/=5;
        }
        sum[i] = sum[i-1]+cnt;
 
    }
}
void numberOfzero2()
{
    for(int i=1; i<=1000009; i+=1)
    {
        int x = i;
        int cnt = 0;
        while(x>0)
        {
            int r = x%2;
            if(r==0)
                cnt++;
            else
                break;
            x/=2;
        }
 
        sum1[i] = cnt+sum1[i-1];
    }
}
 
int zero2(int n)
{
    int c = 0;
 
    while(n>0)
    {
        if(n%2==0)
            c++;
        else
            break;
        n/=2;
    }
    return c;
}
int zero5(int n)
{
    int c = 0;
 
    while(n>0)
    {
        if(n%5==0)
            c++;
        else
            break;
        n/=5;
    }
    return c;
}
 
 
 
int main()
{
    // file;
 
    numberOfzero();
    numberOfzero2();
    int test,n,r,p,q;
    sci(test);
 
    for(int t=1; t<=test; t++)
    {
        sci(n);
        sci(r);
        sci(p);
        sci(q);
        int factN = sum[n];
        int factN2 = sum1[n];
 
        int factR = sum[r];
        int factR2 = sum1[r];
 
        int factN_R = sum[n-r];
        int factN_R2 = sum1[n-r];
 
        int a = factN+q*zero5(p) - (factR+factN_R);
        int b = factN2+q*zero2(p) - (factR2+factN_R2);
 
        int m = min(a,b);
 
        printf("Case %d: ",t);
 
        pri(m),nl;
 
    }
 
    return 0;
}
 
