#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
vector<int> G[maxn];
//要保证图是联通的才行
int fa[maxn];
int n,m,degree[maxn];
int finded(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=finded(fa[x]);
}
void join(int a,int b)
{
    int c1=finded(a),c2=finded(b);
    if(c1!=c2)
        fa[c1]=c2;
}

int main()
{
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        memset(degree,0,sizeof(degree));
        for(int i=1;i<=n;i++) fa[i]=i;

        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            degree[a]++;
            degree[b]++;
            join(a,b);//联通

        }
        int flag=1;
        int cnt=0;
        /*for(int i=1;i<=n;i++)
            if(fa[i]==i) cnt++;
        if(cnt==1)//联通
        {
            for(int i=1;i<=n;i++)
        {
            if(degree[i]%2)//存在奇数点
            {
                flag=0;
                //break;
            }
        }
        if(flag==0)
            printf("0\n");
        else
            printf("1\n");
        }

        else
        {
            printf("0/n");
        }

    }*/
    int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            if(degree[i]%2==0)   cnt1++;
            if(fa[i]==i)    cnt2++;
        }
        if(cnt1==n && cnt2==1)
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }
    return 0;
}
