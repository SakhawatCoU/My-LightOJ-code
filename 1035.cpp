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


struct PrimeFact
{
    long long int n;
    vector<long long int> primeFactors;
    PrimeFact (long long int n) : n(n) {}
    void generatePrimeFactor()
    {
        // primeFactors.clear();
        while(n%2==0)
        {
            primeFactors.push_back(2);
            n/=2;
        }
        for(long long int i=3; i<=sqrt(n); i+=2)
        {
            while(n%i==0)
            {
                primeFactors.push_back(i);
                n/=i;
            }
        }
        if(n>2)
            primeFactors.push_back(n);
    }
};


int main()
{
    long long int  n,m;
    set<lli> st;
    set<lli>::iterator it;
    lli cnt[500];
    int test;
    scanf("%d",&test);
    for(int k=1; k<=test; k++)
    {
        scanf("%lld",&m);
        memset(cnt,0,sizeof cnt);
        st.clear();

        for(lli i=2; i<=m; i++)
        {
            n = i;
            PrimeFact T(n);
            T.generatePrimeFactor();
            for(int i=0; i<T.primeFactors.size(); i++)
            {
                st.insert(T.primeFactors[i]);
                cnt[T.primeFactors[i]]++;
            }
        }
        printf("Case %d: %lld =",k,m);
        int c = 0;
        for(it=st.begin();it!=st.end();++it)
        {
            if(c==0)
            {
                printf(" ");
            }
            else
            {
                printf(" * ");
            }
            c++;
            lli v = *it;
            printf("%lld (%lld)",v,cnt[v]);
        }
        printf("\n");

    }
     return 0;
}
