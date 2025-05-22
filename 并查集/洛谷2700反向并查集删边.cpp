/*思想就是通过并查集操作反向删除最短边，建立最大边，注意连通性判断，祖先可达就是联通*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;
struct node
{
    int u,v,w;
}e[maxn<<1];

bool cmp(node x,node y)
{
    return x.w>y.w;
}

int n,k,a,b,c,temp,f[maxn];
ll ans=0;
bool is[maxn];

int finded(int x)
{
    if(f[x]==x) return x;
    return f[x]=finded(f[x]);
}

void solve()
{
    for(int i=1;i<n;i++)
    {
        int u=e[i].u;
        int v=e[i].v;
        int w=e[i].w;
        int fu=finded(u),fv=finded(v);
        if(is[fu]&&is[fv]) continue;//祖先都是敌人
        f[fu]=fv;//整合到一个并查集里面
        ans-=w;//减去建立的最大边
        if(is[fu]) is[fv]=true;
        else if(is[fv]) is[fu]=true;
        //表示已经和敌人连接，不能再连接其他敌人


    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>temp;
        is[temp]=true;//判断是敌人
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b>>c;
        e[i].u=a,e[i].v=b,e[i].w=c;
        ans+=c;
    }
    for(int i=0;i<=n;i++) f[i]=i;
    sort(e+1,e+1+n-1,cmp);
    solve();
    cout<<ans<<endl;
    return 0;
}
