#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int mod=10007;
struct Edge
{
	int next;  //上一个同起点的边的序号
	int to;  //这条边指向的点
	int w;  //这条边的长度
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
    //freopen("D:\\算法进阶\\树\\in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v,1);
        add(v,u,1);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);

    for(int i=1;i<=n;++i)//枚举中转点，有中转点一定有距离为2,若只链接一个节点，那么不怀疑更新0
    {
        int max1=0,max2=0;//最大的两个权值
        int t1=0,t2=0;//t1代表和的平方，t2代表平方和
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
        suq=(suq+t1-t2+mod)%mod;//这里要加上mod,取余数后不影响原来的suq，同时避免负数

    }
    printf("%d %d\n",maxx,suq);

    return 0;
}
