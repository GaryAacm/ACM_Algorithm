#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int u,v,t,n,m;
vector<int> e[maxn];
int vist[maxn],match[maxn];
bool dfs(int u,int tag)//tag���ڱ���ҵ�Ŀ�꣬��ͬ���˲�һ��
{
    if(vist[u]==tag) return false;
    vist[u]=tag;
    for(auto v:e[u])//��vȥ����e����ǰu��
    {
        if(match[v]==0||dfs(match[v],tag))//δƥ�������һ����������ѡ��
        {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>m>>t;
    while(t--)
    {
        cin>>u>>v;
        e[u].push_back(v);//�����е����ݼ��붯̬����
    }
    int ans=0;
    for(int i=1;i<=n;++i)//�����󲿵�����
    {
        if(dfs(i,i))
        {
            ++ans;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
