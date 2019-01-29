#include<bits/stdc++.h>
using namespace std;
int tree[100009];
int n;
void update(int pos,int val)
{
    while(pos<=n)
    {
        tree[pos]+=val;
        pos += (pos & (-pos));
    }
}
void update1(int l,int r)
{
    update(l,1);
    update(r+1,-1);
}
int query(int pos)
{
    int sum = 0;
    while(pos>0)
    {
        sum+=tree[pos];
        //  cout<<sum<<endl;
        pos -= pos & (-pos);
    }
    return sum;
 
}
char str[100009];
int main()
{
  //  freopen("in.txt","rt",stdin);
    int test;
    int q,l,r,x;
    scanf("%d",&test);
 
    for(int t = 1; t<=test; t++)
    {
        getchar();
        memset(tree,0,sizeof tree);
        scanf("%s",str+1);
        n = strlen(str+1);
        scanf("%d",&q);
        printf("Case %d:\n",t);
        while(q--)
        {
            char a;
            getchar();
            scanf("%c",&a);
            if(a=='I')
            {
                scanf("%d%d",&l,&r);
                update1(l,r);
            }
            else
            {
                scanf("%d",&x);
                int val = query(x);
                if(val%2==0)
                {
                    printf("%c\n",str[x]);
                }
                else
                {
                    int v = str[x] - 48;
                    printf("%d\n",(v^1));
                }
            }
        }
    }
 
 
 
    return 0;
}
