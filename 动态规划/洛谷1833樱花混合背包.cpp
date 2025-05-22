#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int nx,ny,ex,ey,n,tp;
int dp[maxn],a[maxn],b[maxn],c[maxn];
int val[maxn*10],co[maxn*10];

void change()
{
    for(int i=1;i<=n;i++)
    {
        int t=1;
        while(c[i])
        {
            co[++tp]=t*a[i];//合并花费的时间
            val[tp]=t*b[i];//合并价值
            c[i]-=t;
            t*=2;

            if(c[i]<t)//如果剩下的不能再拆，就直接放在一起
            {
                co[++tp]=a[i]*c[i];
                val[tp]=b[i]*c[i];
                break;
            }
        }
    }
}

int main()
{
    scanf("%d:%d%d:%d%d",&nx,&ny,&ex,&ey,&n);
    int t=(ex*60+ey)-(nx*60+ny);//转化时间

    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        if(!c[i]) c[i]=999999;//进行二进制转换，处理混合背包的关键
    }
    change();

    //下面是01背包
    for(int i=1;i<=tp;i++)
    {
        for(int j=t;j>=co[i];j--)
        {
            dp[j]=max(dp[j],dp[j-co[i]]+val[i]);
        }
    }
    cout<<dp[t]<<endl;

    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
int a[10001],c[10001],t[10001],f[10010],n,m;
int main()
{
    int x1,y1,x2,y2;
    scanf("%d:%d %d:%d",&x1,&y1,&x2,&y2);
    if(y1>y2)
    {
        y2+=60;
        x2--;
    }
    m=(x2-x1)*60+y2-y1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&c[i],&t[i]);
    for(int i=1;i<=n;i++)
    {
        if(t[i]==0)
        {
            for(int j=a[i];j<=m;j++)
                f[j]=max(f[j],f[j-a[i]]+c[i]);
        }
        else
        {
            for(int k=1;k<=t[i];k++)
            {
                for(int j=m;j>=a[i];j--)
                {
                    f[j]=max(f[j],f[j-a[i]]+c[i]);
                }
            }
        }
    }
    printf("%d\n",f[m]);
}
*/
