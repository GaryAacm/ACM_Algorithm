#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int u,v,t,n,m;
vector<int> e[maxn];
int vist[maxn],match[maxn];
bool dfs(const int u,const int tag)//tag���ڱ���ҵ�Ŀ�꣬��ͬ���˲�һ��
{
    if(vist[u]==tag) return false;//��ʾ�Ѿ�����ѡ����
    vist[u]=tag;
    for(auto v:e[u])//��vȥ����e����ǰu��
    {
        if(match[v]==0||dfs(match[v],tag))//δƥ�������һ����������ѡ�񣬸�ѡҲ������
        {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main()
{

    //freopen("D:\\�㷨����\\ͼ��\\�����\\in.txt","r",stdin);
    while(scanf("%d",&t)!=EOF&&t)
    {

        scanf("%d%d",&n,&m);
        memset(match,0,sizeof(match));
        memset(vist,0,sizeof(vist));
        for(int i=0;i<=n;i++) e[i].clear();
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&u,&v);
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
    printf("%d\n",ans);
    }

    return 0;
}
