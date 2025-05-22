#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int mod=10007;
struct Edge
{
	int next;  //��һ��ͬ���ıߵ����
	int to;  //������ָ��ĵ�
	int w;  //�����ߵĳ���
};

Edge edge[maxn*2];

int head[maxn];

int cnt = 1;

void add(int u, int v, int w)
{
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int n,u,v;
int w[maxn];
int maxx=0,suq=0;
int main()
{
    //freopen("D:\\�㷨����\\��\\in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v,1);
        add(v,u,1);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);

    for(int i=1;i<=n;++i)//ö����ת�㣬����ת��һ���о���Ϊ2,��ֻ����һ���ڵ㣬��ô�����ɸ���0
    {
        int max1=0,max2=0;//��������Ȩֵ
        int t1=0,t2=0;//t1����͵�ƽ����t2����ƽ����
        for(int j=head[i];j;j=edge[j].next)
        {
            if(w[edge[j].to]>max1)
            {
                max2=max1;
                max1=w[edge[j].to];
            }
            else if(w[edge[j].to]>max2)
                max2=w[edge[j].to];
            t1=(t1+w[edge[j].to])%mod;
            t2=(t2+w[edge[j].to]*w[edge[j].to])%mod;
        }
        t1=t1*t1%mod;
        maxx=max(maxx,max1*max2);
        suq=(suq+t1-t2+mod)%mod;//����Ҫ����mod,ȡ������Ӱ��ԭ����suq��ͬʱ���⸺��

    }
    printf("%d %d\n",maxx,suq);

    return 0;
}
