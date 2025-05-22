/*因为题目只有2种颜色，那么我们把同一种颜色连在一起的放在同一个连通块里面，
也就是把两个点合并，查询的时候如果两个点没有公共祖先，
那么他一定经过了2种颜色，如果是相同的公共祖先，
那么我们只要判断它的节点的颜色是不是查询的颜色
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int fa[maxn],n,m;
char s[maxn];
int col[maxn],ans[maxn];
int Find(int x)
{
    if(x==fa[x]) return x;
    else{
        return fa[x]=Find(fa[x]);
    }
}
void join(int x,int y)
{
    int c1=Find(x),c2=Find(y);
    if(c1!=c2) fa[c1]=c2;
}

int main()
{
    //freopen("D:\\算法进阶\\并查集\\in.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        if(s[u]==s[v]) join(u,v);
    }
    int cnt=0;
    while(m--)
    {
        int u,v;
        char ss;

        cin>>u>>v>>ss;
        if(Find(u)==Find(v)&&s[u]!=ss) ans[++cnt]=0;
        else ans[++cnt]=1;
    }

    for(int i=1;i<=cnt;++i) cout<<ans[i];

    return 0;
}
