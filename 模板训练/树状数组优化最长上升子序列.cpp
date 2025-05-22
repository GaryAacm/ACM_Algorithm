#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;

int n,a[maxn],c[maxn],max_len[maxn];

int lowbit(int k)
{
    return k&(-k);
}

int query(int x)
{
    int res=0;
    while(x>0)
    {
        res=max(res,c[x]);
        x-=lowbit(x);
    }
    return res;
}

void update(int x,int k)
{
    while(x<=n)
    {
        c[x]=max(c[x],k);
        x+=lowbit(x);
    }
}

signed main()
{
    cin>>n;
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        max_len[i]=query(a[i])+1;//查询这个数前面的有多少
        update(a[i],max_len[i]);//更新
    }


}

