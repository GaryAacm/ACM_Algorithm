#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int fa[maxn],n,m,a,b;
int find(int x)
{
    if(x==fa[x]) return x;
    else
        return fa[x]=find(fa[x]);
}
void join(int x,int y)
{
    int c1=find(x),c2=find(y);
    if(c1!=c2) fa[c1]=c2;
}
//上面的是并查集操作
int main()
{
    while(true)
    {
        int ans=0;//保证ans每次为0
        cin>>n;
        if(n==0)
        {

            return 0;
        }
        cin>>m;
        for(int i=1;i<=n;++i)
        {
            fa[i]=i;//初始化
        }
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            join(a,b);
        }
        for(int i=1;i<=n;++i)
        {
            if(find(i)==i)//这里注意是找父亲节点，父亲节点是自己的节点就说明没有路
                ans++;
        }
        cout<<ans-1<<'\n';
    }
    return 0;
}
