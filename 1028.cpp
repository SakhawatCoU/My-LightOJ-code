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
vector<long long int> v;
void primeFactor(long long int n)
{
    long long int i,cnt=0,d,mul=1,m=n;
    while(n%2==0)
    {
        v.push_back(2);
        n/=2;
    }
    for( i=3; i<=sqrt(n); i+=2)
    {
        while(n%i==0)
        {
            v.push_back(i);
            n/=i;
        }
    }
 
    if(n>2)
        v.push_back(n);
 
}
set<long long int> st;
map<long long int,long long int> mp;
int main()
{
    // primeFactor(9);
    int test;
    sci(test);
    long long int val;
 
    for(int t=1; t<=test; t++)
    {
        st.clear();
        mp.clear();
        v.clear();
        scl(val);
        primeFactor(val);
        printf("Case %d: ",t);
        for(auto x:v)
        {
            st.insert(x);
            mp[x]++;
        }
        long long int mul = 1;
        for(auto x:st)
        {
            mul = mul * (mp[x]+1);
        }
        prl(mul-1),nl;
    }
    return 0;
}
 
