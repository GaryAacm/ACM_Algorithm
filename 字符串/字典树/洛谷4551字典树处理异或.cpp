#include<bits/stdc++.h>
using namespace std;
struct node{
    int to;
    int w;
    int nxt;
}edge[2000001];

int head[2000001];
int cnt=-1;

void addedge(int u,int v,int w)
{
    edge[++cnt].nxt=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt;
}
int sum[2000001];

void dfs(int x,int fa)//找到对应的点到根节点的异或值
{
    for(int i=head[x];~i;i=edge[i].nxt)
    {
        int to=edge[i].to;
        int wei=edge[i].w;
        if(to!=fa)
        {
            sum[to]=sum[x]^wei;
            dfs(to,x);
        }
    }
}

//二进制建立字典树
struct trie{
    int ch[2];
}t[2000001];
int tot;
void build(int val,int x){
    for(int i=(1<<30);i;i>>=1){//用30位二进制保存
        bool c=val&i;//取出二进制下这个数的当前位置，是0还是1
        if(!t[x].ch[c]){//当前这个数没有存在
            t[x].ch[c]=++tot;//开辟新的存储位置
        }
        x=t[x].ch[c];//指向下一个存储位置
    }
}

//二进制字典树查询
int query(int val,int x){
    int ans=0;
    for(int i=(1<<30);i;i>>=1){
        bool c=val&i;
        if(t[x].ch[!c]){//如果这一位可以进行异或就沿着这一条往下走
            ans+=i;
            x=t[x].ch[!c];
        }
        else x=t[x].ch[c];//否则就沿着另一条路往下走
    }
    return ans;
}


int main(){
    memset(head,-1,sizeof(head));
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    dfs(1,-1);//预处理出每一个节点到根的异或和
    for(int i=1;i<=n;++i)build(sum[i],0);//建立trie数
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,query(sum[i],0));//查询，取最大值
    }
    printf("%d\n",ans);

    return 0;
}
