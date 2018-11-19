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
#define pii pair<int,int>
#define piii pair<int,string>
using namespace std;
int test;
int p,l;
vector<int>v;
void divisor(int n)
{
    v.clear();
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n/i==i and n%i==0)
        {
            if(n/i>l)
            v.push_back(n/i);
        }
        else if(n/i!=i and n%i==0)
        {
                 if(i>l)
                printf("%d ",i);
 
             if(n/i>l)
            v.push_back(n/i);
        }
    }
}
int main()
{
 
 
 
    sci(test);
 
    for(int i=1; i<=test; i++)
    {
        sci(p);
        sci(l);
 
        printf("Case %d: ",i);
        if(p-l<l)
        {
            printf("impossible\n");
            continue;
        }
        if(p==2 and l==1)
        {
            printf("impossible\n");
            continue;
        }
        divisor(p-l);
        for(int i=v.size()-1; i>=0; i--)
        {
            cout<<v[i];
            if(i!=0)
                spc;
        }
        nl;
    }
 
    return 0;
}
 
