#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
const int maxn=100010;
il int read(){
	int x=0;
	char c=getchar();
	for(;!(c>='0'&&c<='9');c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		x=(x<<1)+(x<<3)+c-'0';
	return x;
}
int T,n;
int a[maxn];
bool vis[maxn];
int tap[maxn];
int st[maxn],top;

int main()
{
    T=read();
    while(T--)
    {
        n=read();
        top=0;

        for(int i=1;i<=n;i++)
            a[i]=read();

        for(int i=1;i<=n;tap[a[i]]++,i++)//记录出现的次数,i++在后面，不然会提前更新
        {
            if(!vis[a[i]])
            {
                vis[a[i]]=1;
                st[++top]=a[i];
            }
        }
        if(top==1) printf("Yes\n");
        else if(top==2&&abs(tap[st[1]]-tap[st[2]])<=1) printf("Yes\n");
        else printf("No\n");
        //memset(vis,0,sizeof(vis));
        //memset(tap,0,sizeof(tap));
        for(int i=1;i<=n;i++) vis[a[i]]=tap[a[i]]=0;
    }
    return 0;
}
