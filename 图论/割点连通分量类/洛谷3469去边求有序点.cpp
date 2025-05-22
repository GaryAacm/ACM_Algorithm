#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;

int num[maxn],low[maxn],dfn=0,judge[maxn];
vector<int> s[maxn];
int ans[maxn],t[maxn];//��¼�𰸺�������С
int n,m,u,v;

void dfs(int u,int fa)
{
    num[u]=low[u]=++dfn;
    t[u]=1;
    int child=0,sum=0;
    for(int i=0;i<s[u].size();i++)
    {
        int v=s[u][i];
        if(!num[v])
        {
            dfs(v,u);
            t[u]+=t[v];//�ݹ��¼������С
            low[u]=min(low[u],low[v]);
            if(num[u]<=low[v])//�з��أ������и�㣬���²�ͬ����ͨ��
            {
                ans[u]+=t[v]*(n-t[v]);//�������������
                sum+=t[v];
                child++;
                if(u!=1||child>1) judge[u]=1;
            }
        }
        else if(num[u]>num[v]&&v!=fa)
        {
            low[u]=min(low[u],num[v]);
        }
    }
    if(!judge[u])
    {
        ans[u]=2*(n-1);
    }
    else ans[u]+=(n-sum-1)*(sum+1)+(n-1);
    return ;
}


signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        s[u].push_back(v);
        s[v].push_back(u);
    }
    dfn=0;
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
        {
            dfs(i,i);

        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

