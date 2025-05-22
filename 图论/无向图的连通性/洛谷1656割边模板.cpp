#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;//��poj�Ǹ���ͬ���Ǹ�����1Ϊ���ڵ㣬����Ҫ���еĵ����
int ans;
struct Edge{int from,to;}edge[maxn];//�𰸵ıߣ������Ҫ����

bool cmp(const Edge a,const Edge b){if(a.from!=b.from)return a.from<b.from;return a.to<b.to;}//�𰸱ߵıȽϺ���

inline void add_edge(int x,int y){edge[ans].from=min(x,y);edge[ans].to=max(x,y);ans++;}//�ڴ��м���һ����

vector<int> v[maxn];
int low[maxn],num[maxn];

int cnt=0;
void dfs(int u,int fa)
{
    low[u]=num[u]=++cnt;//���³�ʼֵ
    //int child=0;
    bool vis=false;
    for(int i=0;i<v[u].size();i++)
    {
        int kid=v[u][i];
        if(!num[kid])//�ӽڵ�û�з��ʹ�,���Լ�������
        {

            dfs(kid,u);//�ݹ����һ��

            if(low[kid]>num[u])//���ڵ㵥���������϶����ˣ������ǷǸ��ڵ�ĲŴ���
            {
                //cout<<"out"<<endl;
                add_edge(u,kid);
            }
            low[u]=min(low[u],low[kid]);//�����ӽڵ��ܹ����˵ĵ�
        }

        else
		{
			if(kid==fa&&!vis)vis=true;//�ж��ظ���
            else  low[u]=min(low[u],num[kid]);
		}

		/*if(num[kid]&&kid!=fa)//���Ҫ��һЩ�ж�����
		{
			//if(kid==fa&&!vis)vis=true;//�ж��ظ���
             low[u]=min(low[u],num[kid]);
		}*/
    }

}
int n,m;
int main()
{

    //freopen("D:\\�㷨����\\ͼ��\\����ͼ����ͨ��\\in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
           dfs(i,i);
    }

    sort(edge,edge+ans,cmp);//���������Ÿ���
    //cout<<ans<<endl;
    for(int i=0;i<ans;i++)
    {
        printf("%d %d\n",edge[i].from,edge[i].to);

    }

    return 0;
}
