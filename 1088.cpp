#include<bits/stdc++.h>
using namespace std;
int arr[100009];
int BNS_left(int val,int low,int up)
{
    int l = 1,r = val,mid;
    int ans=-1;

    while(l<=r)
    {
        mid = l + (r-l)/2;

        if(arr[mid]>=low and arr[mid]<=up)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            if(arr[mid]<low)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return ans;
}

int BNS_right(int val,int low,int up)
{
    int l = 1,r = val,mid;
    int ans=-1;

    while(l<=r)
    {
        mid = l + (r-l)/2;

        if(arr[mid]>=low and arr[mid]<=up)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            if(arr[mid]>up)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return ans;
}
int main()
{
    // freopen("in.txt","rt",stdin);
    long long int test,l,r,n,q;
    scanf("%lld",&test);

    for(int t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&q);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Case %d:\n",t);
        while(q--)
        {
            scanf("%lld %lld",&l,&r);
            int most_left = arr[1];
            int most_right = arr[n];
            if(r<most_left || l>most_right)
            {
                printf("0\n");
                continue;
            }
            int p = BNS_left(n,l,r);
            int p1 = BNS_right(n,l,r);
            if(p==-1 || p1==-1)
                printf("0\n");
            else
                printf("%d\n",p1-p+1);
        }
    }

    return 0;
}
