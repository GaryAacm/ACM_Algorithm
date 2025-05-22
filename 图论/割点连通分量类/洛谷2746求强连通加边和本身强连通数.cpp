#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
vector<int> G[maxn];
int cnt=0,dfn,ans=0;
int low[maxn],top=0;    //low���ܹ����ص���Զ���ȣ�num�ǽڵ����˳��
int num[maxn],scnno[maxn],stacked[maxn];    //scnno������¼��ǰ�������ĸ���ͨ��
int in[maxn],out[maxn],vis[maxn];
int n,m,u,v;

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

void solve(int u)//����������ͼ����Ⱥͳ���
{
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(scnno[u]!=scnno[v])
        {
            in[scnno[v]]++;
            out[scnno[u]]++;

        }

    }

}

int main()
{

    cin>>n;

    for(int i=0;i<=n;i++)
    {
        G[i].clear();
    }
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            cin>>u;
            if(u==0) break;
            G[i].push_back(u);
        }
    }
    int ans2=0,ans3=0;
    Tarjan(n);

    for(int i=1;i<=n;i++) solve(i);
    for(int i=1;i<=cnt;i++)
    {
        if(out[i]==0) ans2++;
        if(in[i]==0) ans3++;
    }

    cout<<ans3<<endl;
    if(cnt==1) cout<<0<<endl;//����ǿ��ͨ����Ҫ����
    else cout<<max(ans2,ans3)<<endl;
    return 0;
}

