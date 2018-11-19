#include<bits/stdc++.h>
#define lli unsigned long long int
#define scf(n) scanf("%lld",&n)
#define rep1(n) for(int i=1;i<=n;i++)
#define prf(n) printf("%lld",n)
#define sci(n) scanf("%d",&n)
#define pri(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define scl(n) scanf("%lld",&n)
#define nl printf("\n")




lli PhiArr[5000009];
int mark[5000009];
int limit,n = 5000009;


void Phi(int n)
{

    int i,j;
    for(i=1; i<=n; i++)
        PhiArr[i] = i;
    PhiArr[1] = 1;
    mark[1] = 1;

    for(i=2; i<=n; i++)
    {
        if(!mark[i])
        {
            for(j = i; j<=n; j+=i)
            {
                mark[j] = 1;
                PhiArr[j] = PhiArr[j] / i * (i-1);
            }
        }
    }
}



int main()
{
    Phi(n);
    PhiArr[1] = 1;
    int i,k;
    for(i=2; i<=5000000; i++)
    {
        PhiArr[i] = PhiArr[i-1] + PhiArr[i]*PhiArr[i];
    }
    int test;
    int l,r;
    lli a;
    scanf("%d",&test);

    for(k=1; k<=test; k++)
    {
        scanf("%d%d",&l,&r);
        a = PhiArr[r]-PhiArr[l-1];
        printf("Case %d: %llu\n",k,a);
    }

    return 0;
}
