#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200010;
struct edge{
    int to,next,w;
}e[maxn<<1];
int n,m,cnt;
int dis1[maxn],dis2[maxn],last[maxn];
int st,ed;
inline void add(int u,int v,int w){
    cnt++;
    e[cnt].to=v;
    e[cnt].next=last[u];
    last[u]=cnt;
    e[cnt].w=w;
}
void dfs1(int u,int fa){
    for(int i=last[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==fa) continue;
        dis1[v]=dis1[u]+e[i].w;
        if(dis1[v]>dis1[st]) st=v;
        dfs1(v,u);
    }
}
void dfs2(int u,int fa){
    for(int i=last[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==fa) continue;
        dis2[v]=dis2[u]+e[i].w;
        if(dis2[v]>dis2[ed]) ed=v;
        dfs2(v,u);
    }
}
void dfs3(int u,int fa){
    for(int i=last[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==fa) continue;
        dis1[v]=dis1[u]+e[i].w;
        dfs3(v,u);
    }
}
void dfs4(int u,int fa){
    for(int i=last[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==fa) continue;
        dis2[v]=dis2[u]+e[i].w;
        dfs4(v,u);
    }
}
signed main(){
    freopen("D:\\算法进阶\\树\\树的直径\\input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    dfs1(1,0);
    dfs2(st,0);
    int ans=dis2[ed];
    cout<<ans<<endl;
    cout<<st<<' '<<ed<<endl;

    memset(dis1,0,sizeof(dis1)),memset(dis2,0,sizeof(dis2));
    dfs3(st,0),dfs4(ed,0);
    int tmp=0;
    for(int i=1;i<=n;i++){//枚举点C
        int d=min(dis1[i],dis2[i]);
        if(d>tmp) tmp=d;
    }
    ans+=tmp;
    cout<<ans;
}
