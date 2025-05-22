#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;

int t,n,m,h;

struct node
{
    int id,fine,val;
}a[maxn];

bool cmp(node x,node y)
{
    if(x.val!=y.val) return x.val>y.val;
    else if(x.fine!=y.fine) return x.fine<y.fine;
    return x.id<y.id;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>h;
        int cost[n+1][m+1];//避免数组过大，开动态的
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>cost[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            sort(cost[i]+1,cost[i]+1+m);//二维数组排序
            int sum=0,cnt=0,tot=0;
            for(int j=1;j<=m;j++)
            {
                sum+=cost[i][j];//花费的时间
                if(sum>h) break;
                cnt++;
                tot+=sum;//罚时
            }
            a[i].fine=tot;
            a[i].val=cnt;
            a[i].id=i;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            if(a[i].id==1)
            {
                cout<<i<<'\n';
                break;
            }
        }
    }
}
