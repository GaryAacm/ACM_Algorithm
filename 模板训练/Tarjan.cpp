#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
vector<int> G[maxn];
int cnt=0,dfn;
int low[maxn],top=0;//low���ܹ����ص���Զ���ȣ�num�ǽڵ����˳��
int num[maxn],scnno[maxn],stacked[maxn];//scnno������¼��ǰ�������ĸ���ͨ��

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
        else if(!scnno[v])//û�мӽ���ͨ��
            low[u]=min(low[u],num[v]);

    }
    if(low[u]==num[u])//��ǰ��ͨ��ĵ������
    {
        cnt++;
        while(1)
            {
                int v=stacked[--top];//��ջ����ʾͬһ������Ԫ��
                scnno[v]=cnt;
                if(u==v) break;//�ҵ�ջ�׵��Ǹ���
            }
    }
}

void Tarjan(int n)
{
    cnt=0;
    top=dfn=0;
    memset(num,0,sizeof(num));
    memset(scnno,0,sizeof(scnno));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
            dfs(i);
    }

}

int main()
{
    int n,m,u,v;
    while(scanf("%d%d",&n,&m),n!=0||m!=0)
    {
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
        printf("%s\n",cnt==1?"Yes":"No");

    }
    return 0;
}
