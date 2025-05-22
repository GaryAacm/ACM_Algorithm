#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
vector<int> G[maxn];
int cnt=0,dfn,ord=0,ans=0;
int low[maxn],top=0;//low���ܹ����ص���Զ���ȣ�num�ǽڵ����˳��
int num[maxn],scnno[maxn],stacked[maxn];

void dfs(int u)
{
    num[u]=low[u]=++dfn;//��һ������Ϊ����˳��
    stacked[top++]=u;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!num[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);//���ϸ��»��˱�
        }
        else if(!scnno[v])
            low[u]=min(low[u],num[v]);//������˱�,��ʵ���Ǵ����ӽڵ�С�ڸ��ڵ�����

    }
    if(low[u]==num[u])//��������
    {
        ord=0;
        bool flag=true;
        cnt++;
        while(1)
            {
                int v=stacked[--top];//��ջ����ʾͬһ������Ԫ��
                scnno[v]=cnt;
                ord++;
                if(ord>=2&&flag)
                {
                    ans++;
                    flag=false;
                }
                if(u==v) break;//�ҵ�����һ��������
            }
    }
}

void Tarjan(int n)
{
    cnt=0;
    top=dfn=0;
    memset(num,0,sizeof(num));
    memset(scnno,0,sizeof(scnno));
    memset(low,0,sizeof(num));
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
            dfs(i);
    }
}

int main()
{
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        G[i].clear();
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    Tarjan(n);
    printf("%d\n",ans);
    return 0;
}

