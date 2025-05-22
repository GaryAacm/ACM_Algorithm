#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;

struct Edge  //ÿһ��edge����һ���ߣ�������Ŵ�����
{
	int next;  //��һ��ͬ���ıߵ����
	int to;  //������ָ��ĵ�
	int w;  //�����ߵĳ���
};

Edge edge[maxn*2];  //���������,����������ǵã�����

int head[101];  //head[i],������iΪ���ıߵ���������head[i]��������������������

int cnt = 1;   //���߱�������¼�ߵ���ţ�˳��(�����˳�㣬������ܷǱ�Ҫ)��¼���м����ߣ�add������һ���Լ�һ��

void add(int u, int v, int w)  //�����u��v�ĳ���Ϊw�ı�
{
    edge[cnt].w = w;  //��cnt���߳�Ϊw
    edge[cnt].to = v;  //��cnt����ָ���v
    edge[cnt].next = head[u];  //��һ����uΪ���������ŵıߵ������head[u]��ÿһ���߶���¼������һ��ͬ���ıߵ���ţ���next
    head[u] = cnt++;  //������uΪ���������ŵıߵ������cnt��
}

int n,a,b;
ll dp[maxn],Size[maxn],d[maxn];
int vist[maxn];

void dfs1(int u,int fa)
{
    Size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(d[v]) continue;//�ҹ���
        d[v]=d[u]+1;
        dfs1(v,u);
        Size[u]+=Size[v];
    }
}

void dfs2(int u,int fa)//���½ڵ�
{
    dp[u]=dp[fa]+n-2*Size[u];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa) continue;

        dfs2(v,u);

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\�㷨����\\��\\in.txt","r",stdin);

    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        add(a,b,1);
        add(b,a,1);

    }
    d[1]=1;
    dfs1(1,0);
    ll maxnn=0;
    int idx;
    for(int i=1;i<=n;i++)
        maxnn+=d[i];//������ڵ�����
    maxnn-=n;
    //cout<<maxnn<<endl;
    dp[1]=maxnn;
    for(int i=head[1];i;i=edge[i].next)//����dp
    {
        int v=edge[i].to;
        dfs2(v,1);
    }
    for(int i=2;i<=n;i++)
    {
        if(maxnn>dp[i])
        {
            maxnn=dp[i];
            idx=i;
        }
    }

    cout<<idx<<' '<<maxnn<<endl;

    return 0;

}
