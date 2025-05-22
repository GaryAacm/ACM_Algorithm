


    #include<cstdio>
    #include<cstring>
    #include<iostream>
    #include<algorithm>
    #define int long long
    using namespace std;
    const int N=2000+10;
    void in(int &x){
    	char ch=getchar();int flag=0;x=0;
    	while(ch<'0'||ch>'9')flag|=(ch=='-'),ch=getchar();
    	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
    	if(flag)x=-x;
    }
    int n,x[N],y[N],val[N],dis[N],fa[N],ans,res[N];
    int way(int i,int j){
    	return abs(x[i]-x[j])+abs(y[i]-y[j]);
    }
    struct node{
    	int from,to,x,flag=0;
    }a[N*N];int tot;
    bool cmp(node q,node p){
    	if(q.x!=p.x)return q.x<p.x;
    	return val[q.from]+val[q.to]<val[p.from]+val[p.to];
    }
    bool cmp1(node q,node p){
    	if(q.from!=p.from)return q.from<p.from;
    	return q.to<p.to;
    }
    int find(int x){
    	if(x!=fa[x])return fa[x]=find(fa[x]);
    	return x;
    }
    signed main(){
    	//freopen(".in","r",stdin);
    	//freopen(".out","w",stdout);
    	in(n);
    	for(int i=1;i<=n;i++)fa[i]=i,in(x[i]),in(y[i]);
    	for(int i=1;i<=n;i++)in(val[i]);
    	for(int i=1;i<=n;i++)in(dis[i]);
    	for(int i=1;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
    			if(i==j)continue;
    			a[++tot].from=i,a[tot].to=j,a[tot].x=(way(i,j)*(dis[i]+dis[j]));
    		}
    	}
    	for(int i=1;i<=n;i++){
    		a[++tot].from=i,a[tot].to=n+1,a[tot].x=val[i];
    	}
    	sort(a+1,a+tot+1,cmp);
    	int m=0,m1=0;
    	//printf("%d\n",ans);
    	for(int i=1;i<=tot;i++){
    	//	printf("%d\n",a[i].x);
    		int x=find(a[i].from),y=find(a[i].to);
    		if(x!=y){
    			if(a[i].to==n+1)res[++res[0]]=a[i].from;
    			a[i].flag=1;
    			fa[x]=y;
    			ans=ans+a[i].x;
    		}
    	}
    	sort(res+1,res+res[0]+1);
    	printf("%I64d\n%I64d\n",ans,res[0]);
    	for(int i=1;i<=res[0];i++){
    		printf("%I64d ",res[i]);
    	}
    	printf("\n%I64d\n",n-res[0]);
    	for(int i=1;i<=tot;i++){
    		if(a[i].from>a[i].to)swap(a[i].from,a[i].to);
    		if(a[i].flag&&a[i].to!=n+1)
    			printf("%I64d %I64d\n",a[i].from,a[i].to);
    	}

    	return 0;
    }
