#include <iostream>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1010;
int low[maxn],cnt;
vector<int> v[maxn];
int n,m;

void dfs(int u,int fa)
{
    low[u]=++cnt;
    for(int i=0;i<v[u].size();i++)
    {
        int kid=v[u][i];
        if(kid==fa) continue;
        if(!low[kid])
        {
            dfs(kid,u);
        }
        low[u]=min(low[u],low[kid]);//������ͨ�ĵ㣬����С����Ϊ����
    }
}

int Tarjan()
{
    int deg[maxn];
    memset(deg,0,sizeof(deg));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(low[v[i][j]]!=low[i])
                deg[low[i]]++;//��ͬ�ĵ㿴��һ�飬����ͬ��++
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==1)//ͳ�ƶ���Ϊ1�ĵ�
            res++;

    }

    return res;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(low,0,sizeof(low));
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cnt=0;
        dfs(1,-1);
        int ans=Tarjan();
        //printf("%d\n",(ans+1)/2);
        printf("%d\n",ans);


    }

    return 0;
}

