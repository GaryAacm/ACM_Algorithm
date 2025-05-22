#include<bits/stdc++.h>
#define INF 0x7f7f7f7f
#define MAXN 100005
using namespace std;

vector<int> g[MAXN];
int n,m,dp[MAXN],mi[MAXN],c[MAXN];//dp表示到了第i个点可以赚取的最多旅费

void dfs(int x,int minx,int pre) {//minx表示当前商品的最小值
    int flag=1;
    minx=min(c[x],minx);
    if (mi[x]>minx) mi[x]=minx,flag=0;//flag表示更新了最小值，避免多余的搜索

    int maxx=max(dp[pre],c[x]-minx);//计算赚取的最值
    if (dp[x]<maxx) dp[x]=maxx,flag=0;//dp更新

    if (flag) return;
    for (int i=0;i<g[x].size();i++) dfs(g[x][i],minx,x);
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<MAXN;i++) mi[i]=INF;
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);
    for (int i=1;i<=m;i++) {
        int t1,t2,t3;
        scanf("%d%d%d",&t1,&t2,&t3);
        g[t1].push_back(t2);
        if (t3==2) g[t2].push_back(t1);
    }
    dfs(1,INF,0);
    printf("%d\n",dp[n]);
    return 0;
}

