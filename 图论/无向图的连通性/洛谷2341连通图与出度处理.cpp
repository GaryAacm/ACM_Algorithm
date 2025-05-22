/*�����һ��˼·�����㷨����ʵ�ֵļ�¼��ͨ���������һ�飬���ǵ���ͬ��ͨ��֮���в�ͬ������·��*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
vector<int> G[maxn];
vector<int> GG[maxn];
int cnt=0,dfn,ans=0,ord=1,now;
int n,m,u,v;
int low[maxn],top=0;//low���ܹ����ص���Զ���ȣ�num�ǽڵ����˳��
int num[maxn],scnno[maxn],stacked[maxn];
int countt[maxn];

int out[maxn],vis[maxn];

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
        cnt++;
        while(1)
            {
                int v=stacked[--top];//��ջ����ʾͬһ������Ԫ��
                scnno[v]=cnt;//��¼������һ����ͨ����
                countt[cnt]++;//��¼��һ���ж��ٸ���
                if(u==v)
                {
                    break;
                }
                //�ҵ�����һ��������
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
void solve()
{
    int num2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            if(scnno[i]!=scnno[G[i][j]])//�ô����Ƚ���ͨ���Ƿ�ͬһ��
            {
                out[scnno[i]]++;//���Ǿͼ��ϳ��ȣ��õ�����һ��ı��

            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        if(!out[i]) num2++,ans=countt[i];
    }

    if(num2>1) printf("0\n");
    else printf("%d\n",ans);
}

int main()
{

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

    solve();
    return 0;
}
