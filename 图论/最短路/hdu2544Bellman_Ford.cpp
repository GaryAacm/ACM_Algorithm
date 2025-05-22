#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int INF=1e6;
int a,b,c,n,m,cnt;
int pre[maxn];
struct Edge
{
    int u,v,wei;
}edge[10005];

void printf_path(int s,int t)//输出路径
{
    if(t==s) {
        printf("%d ",s);return;
    }
    printf_path(s,pre[t]);
    printf("%d ",t);
}

void Bellman()
{
    int s=1;
    int d[maxn];//记录i到s的距离
    for(int i=0;i<=n;i++) d[i]=INF;//初始化距离为无穷大
    d[s]=0;
    for(int i=0;i<cnt;i++)//枚举边
        {
            int x=edge[i].u,y=edge[i].v;
            if(d[x]>d[y]+edge[i].wei)
            {
                d[x]=d[y]+edge[i].wei;
                pre[x]=y;//记录前驱节点，倒退回去计算
            }
        }
        printf("%d\n",d[n]);
        //printf_path(s,n);

    /*for(int k=1;k<=n;k++)
    {


    }*/

    /*判断负圈
    bool update=true;
    while(update)
    {
        k++;
        if(k>n) {printf("负圈!\n") return ;}
        update=false;
        for(int i=0;i<cnt;i++)//枚举边
        {
            int x=edge[i].u,y=edge[i].v;
            if(d[x]>d[y]+edge[i].wei)
            {
                d[x]=d[y]+edge[i].wei;
                update=true;
                pre[x]=y;//记录前驱节点，倒退回去计算
            }
        }
    }
    */
}

int main()
{
    freopen("D:\\算法进阶\\图论\\最短路\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
    {
        cnt=0;//记录边的数目
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            edge[cnt].u=a;
            edge[cnt].v=b;
            edge[cnt].wei=c;
            cnt++;
            edge[cnt].u=b;
            edge[cnt].v=a;
            edge[cnt].wei=c;
            cnt++;
        }
        Bellman();
    }
}
