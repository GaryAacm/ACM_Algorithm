#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;//��poj�Ǹ���ͬ���Ǹ�����1Ϊ���ڵ㣬����Ҫ���еĵ����
vector<int> v[maxn];
int low[maxn],num[maxn],iscut[maxn];
int ssa[maxn];
int cnt=0;
void dfs(int u,int fa)
{
    low[u]=num[u]=++cnt;//���³�ʼֵ
    int child=0;
    for(int i=0;i<v[u].size();i++)
    {
        int kid=v[u][i];
        if(!num[kid])//�ӽڵ�û�з��ʹ�,���Լ�������
        {

            dfs(kid,fa);//�ݹ����һ��
            if(u==fa) child++;
            low[u]=min(low[u],low[kid]);//�����ӽڵ��ܹ����˵ĵ�
            if(low[kid]>=num[u]&&u!=fa)//���ڵ㵥���������϶����ˣ������ǷǸ��ڵ�ĲŴ���
                iscut[u]=1;

        }
         else //�л��˵ı�,һ�����Ѿ����ʹ��ı�(����ĸ��͸���󷨲�ͬ)!!!
            {
                low[u]=min(num[kid],low[u]);
            }
        /*if(num[kid]&&kid!=fa)
		{
			//if(kid==fa&&!vis)vis=true;//�ж��ظ���
             low[u]=min(low[u],num[kid]);
		}*/
    }
    if(u==fa&&child>=2)//����������ڵ�
        iscut[u]=1;
}
int n,m;
int main()
{

    //freopen("D:\\�㷨����\\ͼ��\\P3388_1.in","r",stdin);
    //freopen("123.out","w",stdout);
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

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        ans+=iscut[i];


    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
    {

        if(iscut[i])
            printf("%d ",i);
    }

    return 0;
}
