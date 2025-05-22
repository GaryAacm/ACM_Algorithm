/*����ע����ǽ�����ͼ֮��������������ע����������Ľڵ�˳��ֱ����������������dp��
Ȼ�����dp�������˵�ǰ�ڵ�����Ž�������һ�ڵ�ת���������������˵�˳����ָ��dp˳��*/
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
int dp[maxn];
int in[maxn],vis[maxn],val[maxn];

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
                //cout<<"��ͨ�飺"<<cnt<<"���У�"<<v<<endl;
                countt[cnt]+=val[v];
                //��¼��һ��ȫ�����Ȩֵ
                if(u==v)
                {
                    break;
                }
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

queue<int>Q;

void tuopu()
{
    for(int i=1;i<=cnt;i++)
    {
        if(in[i]==0)
        {
            Q.push(i);
            dp[i]=countt[i];
        }
   }
    while(!Q.empty())
    {
        int u=Q.front();
        //cout<<"��ǰ��ͨ����"<<u<<endl;
        Q.pop();
        for(int i=0;i<GG[u].size();i++)
        {
            int v=GG[u][i];
            //cout<<"��Ӧ�ĵ㣺"<<v<<endl;
            dp[v]=max(dp[v],dp[u]+countt[v]);
            in[v]--;
            if(!in[v])
            {
                Q.push(v);
                //cout<<"���"<<v<<endl;
            }
        }
    }
}

void solve()
{
    //�������
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            if(scnno[i]!=scnno[G[i][j]])
            {
                in[scnno[G[i][j]]]++;
                GG[scnno[i]].push_back(scnno[G[i][j]]);
                //cout<<scnno[i]<<" ͨ��"<<scnno[G[i][j]]<<endl;

            }
        }
    }
    //for(int i=1;i<=cnt;i++) cout<<"��ǰ��ͨ�飺"<<i<<" ��ȣ�"<<in[i]<<"Ȩֵ��"<<countt[i]<<endl;
    tuopu();

    int ans=-1;
    for(int i=1;i<=cnt;i++)
    {
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
}


int main()
{

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&val[i]);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    Tarjan(n);

    solve();
    return 0;
}

