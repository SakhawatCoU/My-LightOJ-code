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
 
lli mod = 1000003;
lli BigMod(lli base,lli pow)
{
    if(pow==0)
        return 1%mod;
 
    if(pow==1)
        return base%mod;
 
    lli x = BigMod(base,pow/2);
 
    x = (x*x)%mod;
 
    if(pow%2)
    {
        x = (x*(base%mod))%mod;
    }
    return x;
}
 
lli fact[1000009];
int main()
{
 
    int i,T;
 
    sci(T);
    fact[0] = 1;
 
    for(int i=1;i<=1000000;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
 
    for(int l=1; l<=T; l++)
    {
        lli n,r;
 
        scl(n);
        scl(r);
        printf("Case %d: ",l);
        lli up = fact[n];
        lli down = (fact[r]*fact[n-r]);
        lli ans = (up*BigMod(down,mod-2))%mod;
        prl(ans),nl;
 
    }
 
    return 0;
}
